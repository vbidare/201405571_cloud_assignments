from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import CPULimitedHost
from mininet.link import TCLink
from mininet.util import dumpNodeConnections
from mininet.log import setLogLevel
import sys

class SingleSwitchTopo(Topo):
    "Single switch connected to n hosts."
    def build(self, x=2, y=4):
        switches = []
        hostNum = 1
        for switchNum in range(y+1):
            if switchNum == 0: continue
            switch = self.addSwitch('s%s' %switchNum)
            switches.append(switch)
            # Python's range(N) generates 0..N-1
            for h in range(x+1):
                if h == 0: continue
                if((hostNum%2)==1):
                    host = self.addHost('h'+str(hostNum), ip="10.0.1.%s/24"%hostNum)
                    self.addLink(host, switch, bw=1)
                else:
                    host = self.addHost('h'+str(hostNum), ip="10.0.2.%s/24"%hostNum)
                    self.addLink(host, switch,bw=2)
                hostNum = hostNum+1
        for i in range(len(switches)-1):
            self.addLink(switches[i],switches[i+1])

def simpleTest(x, y):
    print x, y
    "Create and test a simple network"
    topo = SingleSwitchTopo()
    net = Mininet(topo,host=CPULimitedHost, link=TCLink)
    net.start()
    print "Dumping host connections"
    dumpNodeConnections(net.hosts)
    print "Testing network connectivity"
    net.pingAll()
    net.stop()

if __name__ == '__main__':
    # Tell mininet to print useful information
    setLogLevel('info')
    x = int(sys.argv[1])
    y = int(sys.argv[2])
    simpleTest(x, y)

