import os

houses = [11, 29, 19, 36, 40, 44, 52, 61, 70, 74, 83, 47]
edges=[]
for h1 in houses:
  for h2 in houses:
    if h1 != h2 and (h1, h2) not in edges and (h2, h1) not in edges:
      edges.append((h1, h2))
print str(len(edges))+" edges in this K12 graph.\n Check file named 'input'"

if os.path.isfile("input"):
  os.remove("input")

f = open('input', 'a')
f.write(str(12)+" "+str(66)+"\n")

for e in edges:
  f.write(str(e[0])+" "+str(e[1])+"\n")
