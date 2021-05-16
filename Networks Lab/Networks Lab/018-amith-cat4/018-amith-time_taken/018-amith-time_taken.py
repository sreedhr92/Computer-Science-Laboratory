trace1=open('out.tr','r')
all_lines=trace1.readlines()
start_time=0.0
stop_time=0.0
rec_pkt = 0
for line in all_lines:
	splitted_array=line.split()
	if(splitted_array[4]=='cbr' and splitted_array[3] == 9):
		if(float(splitted_array[1])<start_time):
			start_time=float(splitted_array[1])
	if(splitted_array[4]=='cbr' and splitted_array[0]=='r'):
		if(float(splitted_array[1])>stop_time):
			stop_time=float(splitted_array[1])
		rec_pkt += 1

time_taken = (stop_time-start_time)/rec_pkt
print("average time taken to reach receiver: ",time_taken)

