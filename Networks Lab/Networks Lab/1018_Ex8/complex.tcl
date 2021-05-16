
#initialising the simulator
set ns [new Simulator]
#setting the transmission color
$ns color 0 blue
$ns color 1 red
$ns color 2 green
#initalizing the nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]
set n10 [$ns node]

#setting the trace and animation file in write mode
set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf

#initalising th links
$ns duplex-link $n1 $n3 5Mb 2ms DropTail
$ns duplex-link $n3 $n7 1.5Mb 2ms DropTail
$ns duplex-link $n7 $n9 5Mb 2ms DropTail
$ns duplex-link $n9 $n10 5Mb 2ms DropTail
$ns duplex-link $n3 $n2 5Mb 2ms DropTail
$ns duplex-link $n3 $n6 5Mb 2ms DropTail
#$ns duplex-link $n6 $n7 5Mb 2ms DropTail
$ns duplex-link $n7 $n8 5Mb 2ms DropTail
$ns duplex-link $n4 $n3 5Mb 2ms DropTail
$ns duplex-link $n3 $n5 5Mb 2ms DropTail
$ns duplex-link $n5 $n7 5Mb 2ms DropTail


#setting the orientation of the nodes and links


#my code
#udp connection
#n1->n3
set udp1 [new Agent/UDP]
$udp1 set class_ 1
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
set null3 [new Agent/Null]
$ns attach-agent $n3 $null3
$ns connect $udp1 $null3

#n3->n7
set udp3 [new Agent/UDP]
$udp3 set class_ 1
$ns attach-agent $n3 $udp3
set cbr3 [new Application/Traffic/CBR]
$cbr3 attach-agent $udp3
set null7 [new Agent/Null]
$ns attach-agent $n7 $null7
$ns connect $udp3 $null7

#n7->n8
set udp7 [new Agent/UDP]
$udp7 set class_ 1
$ns attach-agent $n7 $udp7
set cbr7 [new Application/Traffic/CBR]
$cbr7 attach-agent $udp7
set null8 [new Agent/Null]
$ns attach-agent $n8 $null8
$ns connect $udp7 $null8

#tcp connection
#n3->n8
set tcp3_d1 [new Agent/TCP]
$tcp3_d1 set class_ 0
set sink8_d1 [new Agent/TCPSink]
$ns attach-agent $n3 $tcp3_d1
$ns attach-agent $n8 $sink8_d1
$ns connect $tcp3_d1 $sink8_d1
set ftp3_d1 [new Application/FTP]
$ftp3_d1 attach-agent $tcp3_d1
#n3->n9
set tcp3_d2 [new Agent/TCP]
$tcp3_d2 set class_ 0
set sink9_d2 [new Agent/TCPSink]
$ns attach-agent $n3 $tcp3_d2
$ns attach-agent $n9 $sink9_d2
$ns connect $tcp3_d2 $sink9_d2
set ftp3_d2 [new Application/FTP]
$ftp3_d2 attach-agent $tcp3_d2
#n3->n10
set tcp3_d3 [new Agent/TCP]
$tcp3_d3 set class_ 0
set sink10_d1 [new Agent/TCPSink]
$ns attach-agent $n3 $tcp3_d3
$ns attach-agent $n10 $sink10_d1
$ns connect $tcp3_d3 $sink10_d1
set ftp3_d3 [new Application/FTP]
$ftp3_d3 attach-agent $tcp3_d3

#n7->n9
set tcp7 [new Agent/TCP]
$tcp7 set class_ 0
set sink9 [new Agent/TCPSink]
$ns attach-agent $n7 $tcp7
$ns attach-agent $n9 $sink9
$ns connect $tcp7 $sink9
set ftp7 [new Application/FTP]
$ftp7 attach-agent $tcp7

#n9->n10
set tcp9 [new Agent/TCP]
$tcp9 set class_ 0
set sink10 [new Agent/TCPSink]
$ns attach-agent $n9 $tcp9
$ns attach-agent $n10 $sink10
$ns connect $tcp9 $sink10
set ftp9 [new Application/FTP]
$ftp9 attach-agent $tcp9

#n3->n2
set tcp3 [new Agent/TCP]
$tcp3 set class_ 0
set sink2 [new Agent/TCPSink]
$ns attach-agent $n3 $tcp3
$ns attach-agent $n2 $sink2
$ns connect $tcp3 $sink2
set ftp3 [new Application/FTP]
$ftp3 attach-agent $tcp3

#n3->n6
set tcp3_1 [new Agent/TCP]
$tcp3_1 set class_ 0
set sink6 [new Agent/TCPSink]
$ns attach-agent $n3 $tcp3_1
$ns attach-agent $n6 $sink6
$ns connect $tcp3_1 $sink6
set ftp3_1 [new Application/FTP]
$ftp3_1 attach-agent $tcp3_1

#n6->n7
set tcp6 [new Agent/TCP]
$tcp6 set class_ 2
set sink7 [new Agent/TCPSink]
$ns attach-agent $n6 $tcp6
$ns attach-agent $n7 $sink7
$ns connect $tcp6 $sink7
set ftp6 [new Application/FTP]
$ftp6 attach-agent $tcp6

#n4->n3
set tcp4 [new Agent/TCP]
$tcp4 set class_ 0
set sink3 [new Agent/TCPSink]
$ns attach-agent $n4 $tcp4
$ns attach-agent $n3 $sink3
$ns connect $tcp4 $sink3
set ftp4 [new Application/FTP]
$ftp4 attach-agent $tcp4

#n3->n5
set tcp3_2 [new Agent/TCP]
$tcp3_2 set class_ 0
set sink5 [new Agent/TCPSink]
$ns attach-agent $n3 $tcp3_2
$ns attach-agent $n5 $sink5
$ns connect $tcp3_2 $sink5
set ftp3_2 [new Application/FTP]
$ftp3_2 attach-agent $tcp3_2

#n5->n7
set tcp5 [new Agent/TCP]
$tcp5 set class_ 0
set sink7_1 [new Agent/TCPSink]
$ns attach-agent $n5 $tcp5
$ns attach-agent $n7 $sink7_1
$ns connect $tcp5 $sink7_1
set ftp5 [new Application/FTP]
$ftp5 attach-agent $tcp5



#running the code
$ns at 0.0 "$cbr1 start"
$ns at 0.1 "$cbr3 start"
$ns at 0.2 "$cbr7 start"
$ns at 0.3 "$ftp7 start"
$ns at 0.4 "$ftp9 start"
$ns at 0.5 "$ftp3 start"
$ns at 0.6 "$ftp3_1 start"
$ns at 0.7 "$ftp6 start"
$ns at 0.8 "$ftp4 start"
$ns at 0.9 "$ftp3_2 start"
$ns at 0.9 "$ftp3_d1 start"
$ns at 0.9 "$ftp3_d2 start"
$ns at 0.9 "$ftp3_d3 start"
$ns at 1.0 "$ftp5 start"

$ns at 1.5 "finish"

proc plotWindow {tcpSource outfile} {
   global ns
   set now [$ns now]
   set cwnd [$tcpSource set cwnd_]

# the data is recorded in a file called congestion.xg (this can be plotted # using xgraph or gnuplot. this example uses xgraph to plot the cwnd_
   puts  $outfile  "$now $cwnd"
   $ns at [expr $now+0.1] "plotWindow $tcpSource  $outfile"
}

set outfile [open  "congestion.xg"  w]

$ns  at  0.0  "plotWindow $tcp7  $outfile"
$ns  at  0.0  "plotWindow $tcp3_d1 $outfile"
$ns  at  0.0  "plotWindow $tcp3_d2 $outfile"

proc finish {} {
	global ns f nf
	$ns flush-trace
	close $f
	close $nf
	puts "running nam..."
	exec nam out.nam &
	exec xgraph congestion.xg -geometry 300x300 &
	exit 0
}

$ns run

