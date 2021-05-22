c = ['A','B','C','D','E']
initial_state = dict()
goal = 0

def manhattan_distance(mx,my):
  sum = 0
  for i in c:
	x,y = initial_state[i]
	sum += abs(x-mx)+abs(y-my)
  return sum

def hill_climbing(mx,my,n,m):
  a=mx
  b=my
  mid = manhattan_distance(mx,my)
  # exploring next states and getting the point which yields the minimum manhattan_distance...
  if mx - 1 !=-1 :
	dist = manhattan_distance(mx-1,my)
	if  dist < mid:
	  mid = dist
	  a = mx-1
	  b = my
	  #print("1",a, b, mid)
  if mx + 1 !=m:
	dist = manhattan_distance(mx+1,my)
	if dist < mid:
	  mid = dist
	  a = mx+1
	  b = my
	  # print("2",a, b, mid)
  if my -1 != -1:
	dist = manhattan_distance(mx,my-1)
	if dist < mid:
	  mid = dist
	  a = mx
	  b = my -1
	  # print("3",a, b, mid)
  if my + 1!=n:
	dist = manhattan_distance(mx,my+1)
	if dist < mid:
	  mid = dist
	  a = mx
	  b = my +1
	  # print("4",a, b, mid)

  if a == mx and b == my:
	print("The midpoint (local_minima) is ({},{})".format(mx, my))
	print("The minimum distance = ",mid)
	return None
  else:
	# print(a,b,mid)
	hill_climbing(a,b,n,m)

max_x = 0
max_y = 0
min_x = 100
min_y = 100
n=9
m=10
for i in c:
  x = int(input("Enter the x - coordinate of {}:".format(i)))
  y = int(input("Enter the y - coordinate of {}:".format(i)))
  if x > max_x:
	max_x = x
  if x < min_x:
	min_x = x
  if y > max_y:
	max_y = y
  if y < min_y:
	min_y = y
  initial_state[i] = (x,y)

mx = (max_x + min_x)//2
my = (max_y + min_y)//2
print("Initial Point",mx,my)
hill_climbing(mx,my,n,m)