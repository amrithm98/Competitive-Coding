def find_cost(n, m):
	global base
	cost = 0
	for i in range(n):
		cost += (max(base-i, 1) ** 2)
	return 1000*cost, m

t = input()
m = {}
for i in range(t):
	n, base = map(int, raw_input().split())
	a = map(int, raw_input().split())
	cost = {}
	l = len(a)
	tcost = 0
	if (len(a)%2 == 0):
		b = a[l/2:]
		a = a[:l/2]
		max_a = max(a)
		max_b = max(b)
		if max_a > max_b:
			ind = a.index(max_a)
			max_ind = ((l/2) - 1)  - ind
			max_height = max_a + max_ind
		elif (max_b > max_a):
			ind = len(b) - 1 - b[::-1].index(max_b)
			max_height = max_b + ind
		else:
			inda = a.index(max_a)
			indb = len(b) - 1 - b[::-1].index(max_b)
			indb1 = len(b) - 1 - indb
			if (inda <= indb1):
				ind = inda
				max_height = max_a + ((l/2) - 1) - ind
			else:
				max_height = max_b + indb
				ind = indb
		la = len(a)
		for j in range(la):
			height = max_height - (la - 1) + j
			increase = height - a[j]
			if (increase != 0):
				if increase in cost.keys():
					tcost += cost[increase]
				else:
					incost, m =  find_cost(increase, m)
					cost[increase] = incost
					tcost += incost
		for j in range (la):
			height = max_height - j
			increase = height - b[j]
			if (increase != 0):
				if increase in cost.keys():
					tcost += cost[increase]
				else:
					incost, m =  find_cost(increase, m)
					cost[increase] = incost
					tcost += incost
		print tcost
	else:
		max_a = max(a)
		f = a.index(max_a)
		rf = l - 1 - a[::-1].index(max_a)
		indf = f
		indrf = l - 1 - rf
		minind = min(indf, indrf)
		max_height = (l/2) - minind + max_a
		la = l/2
		for j in range(la):
			height = max_height - la + j
			increase = height - a[j]
			if (increase != 0):
				if increase in cost.keys():
					tcost += cost[increase]
				else:
					incost, m = find_cost(increase, m)
					cost[increase] = incost
					tcost += incost
		increase = max_height - a[l/2]
		if (increase != 0):
			if increase in cost.keys():
				tcost += cost[increase]
			else:
				incost, m = find_cost(increase, m)
				cost[increase] = incost
				tcost += incost
		b = a[l/2+1:]
		for j in range(la):
			height = max_height - j - 1
			increase = height - b[j]
			if (increase != 0):
				if increase in cost.keys():
					tcost += cost[increase]
				else:
					incost, m = find_cost(increase, m)
					cost[increase] = incost
					tcost += incost
		print tcost		



