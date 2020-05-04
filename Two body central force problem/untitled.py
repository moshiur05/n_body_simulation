from matplotlib import pyplot as plt

x1 = []
y1 = []
x2 = []
y2 = []

i = float(input())
while i != 'end' :
	x1.append(float(i))
	y1.append(float(input()))
	x2.append(float(input()))
	y2.append(float(input()))
	i = input()

plt.plot(x1,y1)
plt.plot(x2,y2)
plt.show()