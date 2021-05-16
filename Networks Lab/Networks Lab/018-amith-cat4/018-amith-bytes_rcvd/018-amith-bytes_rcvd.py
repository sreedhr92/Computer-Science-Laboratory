trace1=open('out.tr','r')
all_lines=trace1.readlines()
received_bytes1 = 0
received_bytes2 = 0
for line in all_lines:
	splitted_array=line.split()
	if(splitted_array[4]=='tcp' and splitted_array[3] == '7'):
		received_bytes1 += int(splitted_array[5])
	if(splitted_array[4]=='ack' and splitted_array[3]=='1'):
		received_bytes2 += int(splitted_array[5])

print("Bytes received by node 1: ",received_bytes2)
print("Bytes received by node 7: ",received_bytes1)

