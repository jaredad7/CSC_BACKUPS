mortal(X):- man(X).
man(X):- philosopher(X); hero(X).
philosopher(X):- teacher(X).
taught(X,Y):- X=socrates,Y=plato ; X=plato,Y=aristotle ; X=aristotle,Y=alexander.
killed(X):- socrates=X; achilles=X.
conquerer(X):- X=alexander; X=odysseus.
teacher(socrates).
teacher(plato).
teacher(aristotle).
student(plato).
student(aristotle).
student(alexander).
hero(alexander).
hero(achilles).
hero(odysseus).
god(zeus).
