import numpy as np
import matplotlib.pyplot as plt

c1 = np.genfromtxt("meshX1.dat")
c2 = np.genfromtxt("A.dat")
c3 = np.genfromtxt("O.dat")

elips = np.loadtxt('ellipse.dat',dtype='double')
plt.plot(elips[0,:],elips[1,:],label='ELLIPSE')

plt.plot(c2,c3)

plt.legend()
plt.axis('equal')
plt.grid()
plt.show()
plt.xlabel('$x$')
plt.ylabel('$y$')
