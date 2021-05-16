set ns [new Simulator]

$ns color 0 violet
$ns color 1 green
$ns color 2 orange
$ns color 3 red

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


set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf

$ns duplex-link $n1 $n5 5Mb 2ms DropTail
$ns duplex-link $n2 $n5 5Mb 2ms DropTail
$ns duplex-link $n3 $n5 5Mb 2ms DropTail
$ns duplex-link $n4 $n5 5Mb 2ms DropTail
$ns duplex-link $n5 $n6 1.5Mb 2ms DropTail
$ns duplex-link $n6 $n7 5Mb 2ms DropTail
$ns duplex-link $n6 $n8 5Mb 2ms DropTail
$ns duplex-link $n6 $n9 5Mb 2ms DropTail
$ns duplex-link $n6 $n10 5Mb 2ms DropTail

$ns duplex-link-op $n5 $n1 orient up
$ns duplex-link-op $n5 $n2 orient left-up
$ns duplex-link-op $n5 $n3 orient left-down
$ns duplex-link-op $n5 $n4 orient down
$ns duplex-link-op $n5 $n6 orient right
$ns duplex-link-op $n6 $n7 orient up
$ns duplex-link-op $n6 $n8 orient right-up
$ns duplex-link-op $n6 $n9 orient right-down
$ns duplex-link-op $n6 $n10 orient down

#udp 2-8
set udp0 [new Agent/UDP]
$ns attach-agent $n2 $udp0
$udp0 set class_ 0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0
set null0 [new Agent/Null]
$ns attach-agent $n8 $null0

#udp 3-9
set udp1 [new Agent/UDP]
$ns attach-agent $n3 $udp1
$udp1 set class_ 1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
set null1 [new Agent/Null]
$ns attach-agent $n9 $null1

$ns connect $udp0 $null0
$ns connect $udp1 $null1

$ns at 0.8 "$cbr0 start"
$ns at 1.1 "$cbr1 start"

#tcp 1-7
set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
set sink1 [new Agent/TCPSink]
$ns attach-agent $n1 $tcp1
$ns attach-agent $n7 $sink1
$ns connect $tcp1 $sink1
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ns at 0.2 "$ftp1 start"


#tcp 4-8
set tcp2 [new Agent/TCP]
$tcp2 set class_ 3
set sink2 [new Agent/TCPSink]
$ns attach-agent $n4 $tcp2
$ns attach-agent $n8 $sink2
$ns connect $tcp2 $sink2
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ns at 0.5 "$ftp2 start"

$ns at 2.8 "$ns detach-agent $n4 $tcp2 ; $ns detach-agent $n8 $sink2"


puts [$cbr0 set packetSize_]
puts [$cbr0 set interval_]

$ns at 3.0 "finish"

proc plotWindow {tcpSource outfile} {
   global ns
   set now [$ns now]
   set cwnd [$tcpSource set cwnd_]
   puts  $outfile  "$now $cwnd"
   $ns at [expr $now+0.1] "plotWindow $tcpSource  $outfile"
}

set outfile [open  "congestion.xg"  w]
$ns  at  0.0  "plotWindow $tcp1  $outfile"
$ns  at  0.0  "plotWindow $tcp2  $outfile"


proc finish {} {
	global ns f nf
	$ns flush-trace
	close $f
	close $nf
	puts "running nam..."
	exec nam out.nam &
	puts "running xgraph..."
	exec /root/Downloads/XGraph4.38_linux64/bin/xgraph congestion.xg &
	exit 0
}

$ns run
