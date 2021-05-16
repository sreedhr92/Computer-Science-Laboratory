trace1=open('out.tr','r')
all_lines=trace1.readlines()
start_time=0.0
recvd_size=0
stop_time=0.0
sent_pkt=0
recived_pkt=0
drop_pkt=0
throughput=0
for line in all_lines:
	splited_array=line.split()
	if(splited_array[4]=='cbr' and (splited_array[0]=='+' or splited_array[0]=='s')):
		if(float(splited_array[1])<start_time):
			start_time=float(splited_array[1])
		sent_pkt=sent_pkt+1
	if(splited_array[4]=='cbr' and splited_array[0]=='r'):
		if(float(splited_array[1])>stop_time):
			stop_time=float(splited_array[1])
		recived_pkt=recived_pkt+1
	if(splited_array[4]=='cbr' and splited_array[0]=='d'):
		drop_pkt=drop_pkt+1

throughput=recived_pkt/(stop_time-start_time)
throughput=throughput/1024
print("For CBR mode: -")
print("Throughput: ",throughput)
print("Dropped packets: ",drop_pkt)
start_time=0.0
recvd_size=0
stop_time=0.0
sent_pkt=0
recived_pkt=0
drop_pkt=0
throughput=0
for line in all_lines:
	splited_array=line.split()
	if(splited_array[4]=='tcp' and (splited_array[0]=='+' or splited_array[0]=='s')):
		if(float(splited_array[1])<start_time):
			start_time=float(splited_array[1])
		sent_pkt=sent_pkt+1
	if(splited_array[4]=='tcp' and splited_array[0]=='r'):
		if(float(splited_array[1])>stop_time):
			stop_time=float(splited_array[1])
		recived_pkt=recived_pkt+1
	if(splited_array[4]=='tcp' and splited_array[0]=='d'):
		drop_pkt=drop_pkt+1

throughput=recived_pkt/(stop_time-start_time)
throughput=throughput/1024
print("For TCP mode: -")
#print("Throughput: ",throughput)
print("Dropped packets: ",drop_pkt)
