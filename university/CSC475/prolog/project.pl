%List lots and lots of facts about persons, fish, cats, dogs, and flowers.
%Predicates for this system include typeof(X,Y), isa(X,Y), haspart(X,Y), and doesact(X,Y)
%If X is a typeof Y, it means that Y is above X heirarchically.
%If X isa Y, it means that X inherits type from Y somewhere along the chain.
%If X haspart Y, it means that all X's have the part Y
%If X doesact Y, it means that all X's perform the action Y.

%The typeof list
typeof(animal,livingthing).
typeof(plant,livingthing).
typeof(flower,plant).
typeof(mammal,animal).
typeof(person,mammal).
typeof(fish,animal).
typeof(cat,mammal).
typeof(dog,mammal).

%Capture the transitive nature of typeof
isa(X,Y):- typeof(X,Y).
isa(X,Z):- typeof(X,Y), isa(Y,Z).

%The haspart list
haspart(animal,head).
haspart(animal,mouth).
haspart(animal,eyes).
haspart(animal,nose).
haspart(animal,ears).
haspart(animal,teeth).

haspart(plant,leaf).
haspart(plant,root).
haspart(plant,stem).

haspart(mammal,torso).
haspart(mammal,legs).
haspart(mammal,feet).
haspart(mammal,fur).

haspart(fish,fin).
haspart(fish,scales).
haspart(fish,gills).

haspart(cat,claws).
haspart(dog,claws).
haspart(cat,tail).
haspart(dog,tail).

haspart(person,fingers).
haspart(person,toes).
haspart(person,hands).
haspart(person,reason).
haspart(person,arms).

haspart(flower,bud).
haspart(flower,petals).
haspart(flower,pollen).

haspart(X,Y):- typeof(X,Z), haspart(Z,Y).

%The doesact list
doesact(livingthing,breathes).
doesact(livingthing,metabolizes).
doesact(livingthing,grows).
doesact(livingthing,reproduces).
doesact(livingthing,adapts).

doesact(animal,moves).
doesact(animal,eats).
doesact(animal,feels).
doesact(animal,sees).
doesact(animal,smells).
doesact(animal,tastes).
doesact(animal,hears).

doesact(plant,photosynthesizes).

doesact(mammal,walks).
doesact(mammal,runs).
doesact(mammal,gestates).

doesact(cat,hisses).
doesact(dog,barks).
doesact(person,speaks).

doesact(person,thinks).
doesact(person,reads).
doesact(person,writes).
doesact(person,builds).

doesact(X,Y):- typeof(X,Z), doesact(Z,Y).

