import pickle
#Load a file at startup. Add an entry to dictionary in file.

#load dictionary
dictionary = pickle.load(open("data.sav", "rb"))
#get data from user
i1 = str(input("Input1: "))
i2 = str(input("Input2: "))
key = str(input("Key: "))
dictionary[key] = [i1, i2]

#print dictionary
print(dictionary)

#save dictionary
pickle.dump(dictionary, open("data.sav", "wb"))
