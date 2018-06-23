#Using Sets
#Run with command 'python3' in order to demonstrate each concept
print("Curly braces give an unordered set.")
x={3,4,8}
print(x)
print("\n")
print("Regular Parentheses give an ordered set.")
x=(3,4,8)
print(x)
print("\n")
print("Square brackets will create a list, which is like an array and can be indexed.")
x=[1,2,3]
print(x)
print(x[0])
print(x[0:2])
print(x[1:3])
print("\n")
print("We can also have sets of sets or lists of lists.")
x=[[11,12,13],[21,22,23],[31,32,33]]
print(x)
print(x[0])
print(x[0][1])
print("\n")
print("Dictionaries are a wonderful data structure for organizing pairs of data.")
print("Dictionary entries consist of a key and a datum.")
x={'key1':1, 'key2':2}
print(x)
print(x['key1'])
print("\n")
print("We can place other data structures within a dictionary.")
x={'A':(1,2,3),'B':[4,5,6],'key0':14}
print(x)
print(x['A'])
print(x['B'][1])
print("\n")
print("Using minuses in accessing arrays begins counting backwards.")
x=[1,2,3,4,5,6,7,8,9]
print(x)
print(x[-1])
print(x[-5])
print("\n")
print("Accessing data outside of an array's range gives us nothing.")
print(x)
print(x[10:20])
print("\n")
print("We can also test for appearance of a value in a set.")
print(x)
boolean=1 in x
print(boolean)
y=17
print(y in x)
print(y not in x)
print("\n")
print("We can also iterate through a set or dictionary with a 'for each' loop.")
print(x)
for y in x:
	print(y)
x={'jean':'whoami','javert':'stars','marius':'red and black'}
print(x)
for y in x:
	print(y)
print("\n")
print("We can AND and OR sets together.")
s1={1,2,3,4,5}
s2={3,4,5,6,7}
print(s1)
print(s2)
print(s1 & s2)
print(s1 | s2)
