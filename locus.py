import numpy as np
import matplotlib.pyplot as plt

c1 = np.genfromtxt("meshX1.dat")
c2 = np.genfromtxt("V.dat")
c3 = np.genfromtxt("u.dat")
c4 = np.genfromtxt("F.dat")
c5 = np.genfromtxt("theta.dat")
c6 = np.genfromtxt("a.dat")
c7 = np.genfromtxt("b.dat")
c8 = np.genfromtxt("A.dat")
c9 = np.genfromtxt("O.dat")

len = 10000
y = np.zeros((2,len))

y[0,:] = c6*np.cos(c5)
y[1,:] = c7*np.sin(c5)

plt.plot(y[0,:],y[1,:],label = '$locus$')
plt.plot(c9,c8)

plt.legend()
plt.axis('equal')
plt.grid()
plt.show()
plt.xlabel('$x$')
plt.ylabel('$y$')
