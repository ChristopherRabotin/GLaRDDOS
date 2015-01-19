#include "socketplant.h"

SocketPlant::SocketPlant(QHostAddress *src, QHostAddress *dest,int srcPort, int destPort, QString payload, signed int pktsToSend, bool randomizeSrcPort, bool randomizeDestPort, bool randomizePkts, bool forceTCPRst)
{
    currentElementThruPortal = 0;
    maxElementsThruPortal = pktsToSend;
    forcePortalRst = forceTCPRst;
    randomCakeIngredients = randomizePkts, randomSourcePortal = randomizeSrcPort, randomDestPortal = randomizeDestPort;
    theCakeIsBaking = true;
    /* plant the oven seed */
    srandom((unsigned int)time(NULL));
    /* point the iph to the beginning of the packet */
    iph = (struct iphdr *) datagram;
    /* point the tcph to the beginning of the IP packet */
    tcph = (struct tcphdr *) (datagram + sizeof (struct iphdr));
    memset(datagram, 0, PCKT_LEN);

    if ((sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
        perror("Raw socket() error. Got root?");
        exit(-1);
    }

    din.sin_family = AF_INET;
    din.sin_port = htons(destPort);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(srcPort);
    sin.sin_addr.s_addr = inet_addr(src->toString().toStdString().c_str());
    inet_pton(AF_INET, dest->toString().toStdString().c_str(), (struct in_addr *)&din.sin_addr.s_addr);
    memset(din.sin_zero, 0, sizeof(din.sin_zero));
    /** TCP header are filled in, IP headers are fill in!
        NEVER A MISCOMMUNICATION! You can't explain that! */
    iph->ihl = 5;
    iph->version = 4;
    iph->tos = 0;
    iph->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
    iph->frag_off = 0;		/* no fragment */
    iph->ttl = 255;		/* default value */
    iph->protocol =IPPROTO_TCP; //IPPROTO_RAW;	/* protocol at L4 || IPPROTO_TCP ?*/
    iph->check = 0;		/* don't ask instead read below */
    iph->saddr = sin.sin_addr.s_addr;
    iph->daddr = din.sin_addr.s_addr;
    iph->check = this->checksum();
    /* TCP H34DR */
    randomizePkt();
    /* use the provided ports for at least the first packet */
    tcph->dest = din.sin_port;
    tcph->source = sin.sin_port;
    tcph->syn = 1;
    tcph->ack = 0;
    tcph->ack_seq = 0;
    tcph->doff = 5; // no offset
    tcph->urg = 0;
    tcph->psh = 0;
    tcph->fin = 0;
    //memset(datagram+sizeof(iph)+sizeof(tcph)+1, payload.toStdString().c_str()[0], sizeof(datagram)-sizeof(iph)-sizeof(tcph));
    spID = random()+time(NULL);
    std::cout << "SP: " << src->toString().toStdString() << ":" << srcPort << " (rd=" << randomizeSrcPort << ") 8===> " << dest->toString().toStdString() << ":" << destPort << " (rd=" << randomizeDestPort << "), ID = " << spID << std::endl;

}
// TODO correct checksum
unsigned short SocketPlant::checksum()
{
    unsigned long sum;
    unsigned short *buf = (unsigned short *)datagram;
    unsigned int len = iph->tot_len;
    for(sum=0; len>0; len--)
        sum += *buf++;
    sum = (sum >> 16) + (sum &0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

void SocketPlant::theCakeIsALie()
{
    SocketPlant::theCakeIsBaking = false;
}

void SocketPlant::randomizePkt()
{
    tcph->seq = htonl(random());
    if(randomSourcePortal) tcph->source = htons(random()%65535);
    if(randomDestPortal) tcph->dest = htons(random()%65535);
    tcph->window = htons(random()%65535);
    tcph->ack = 0;
    tcph->ack_seq = 0;
    tcph->psh = 0;
}

void SocketPlant::alterPortal()
{
    tcph->seq = htonl(ntohl(tcph->seq)+1);
    tcph->ack = 1;
    tcph->ack_seq = htonl(random());
    /* I DON'T ALWAYS SET THE PUSH FLAG BUT WHEN I DO,
       YOU WILL LOOK LIKE MISUNDERSTOOD MITCH. */
    tcph->psh = random()%2==0;
}

void SocketPlant::run(){
    if/*while*/(theCakeIsBaking) {
        //sleep(1);
        this->currentElementThruPortal++;
        if(currentElementThruPortal >= maxElementsThruPortal){
            theCakeIsALie();
        }
        if (sendto(sd, (char *)datagram, sizeof(datagram), 0,
                   (struct sockaddr *)&din, (socklen_t)sizeof(din)) < 0)
            perror("packet send error:");
        else
            std::cout << spID << " @ " << this->currentElementThruPortal << "/" << this->maxElementsThruPortal << std::endl;
        if(forcePortalRst && currentElementThruPortal % 2 == 1){
            alterPortal();
        }else if(randomCakeIngredients){
            randomizePkt();
        }
    }
}

void SocketPlant::qcr(){
  //  QtConcurrent::run(alterPortal);
}

bool SocketPlant::isTheCakeBaking(){
    return theCakeIsBaking;
}
