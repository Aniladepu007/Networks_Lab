set ns [ new Simulator ]
#define diff colors for data flows
$ns color 1 Blue
$ns color 2 Red

#creating trace file
set tracefile [ open out.tr w ]
$ns trace-all $tracefile

#creating nam file for visualisation
set namfile [ open out.nam w ]
$ns namtrace-all $namfile

proc finish {} {
      #global-- says that the file pointers are declared outside the proc
      global ns tracefile namfile
      $ns flush-trace
      close $tracefile
      close $namfile
      exec nam out.nam &
      exit 0
}

#creating 4 nodes
set n0 [ $ns node ]
set n1 [ $ns node ]
set n2 [ $ns node ]
set n3 [ $ns node ]

$ns duplex-link $n0 $n2 15Mb 5ms DRR
$ns duplex-link $n1 $n2 10Mb 10ms DRR
$ns duplex-link $n2 $n3 5.5Mb 20ms DRR

#setting queue size of links
$ns queue-limit $n2 $n3 10

#give node positions
$ns duplex-link-op $n0 $n2 orient left-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient left

#monitor the queue for link
$ns duplex-link-op $n2 $n3 queuePos 0.5
#setup TCP connection
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

#setting up FTP over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
#$ftp set type_ FTP

$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 4.0 "finish"
$ns run
