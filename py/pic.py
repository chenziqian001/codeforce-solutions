import numpy as np
import matplotlib.pyplot as plt

f=plt.figure()
a=f.add_subplot(111,projection='3d')

t,p=np.mgrid[0:2*np.pi:100j,0:np.pi/4:50j]
a.plot_surface(2*np.sin(p)*np.cos(t),2*np.sin(p)*np.sin(t),2*np.cos(p),cmap='Blues',alpha=0.9)

u,v=np.mgrid[0:np.sqrt(2):50j,0:2*np.pi:100j]
a.plot_surface(u*np.cos(v),u*np.sin(v),u,cmap='Oranges',alpha=0.9)

a.set_box_aspect([1,1,1])
a.set_xlabel('X')
a.set_ylabel('Y')
a.set_zlabel('Z')
plt.show()