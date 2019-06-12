import numpy as np
import random
import matplotlib.pyplot as plt
points_x = np.ones(1720)
points_y = np.ones(1720)
def draw_points(a,b,size):
    fig = plt.figure(figsize=(13, 6.5))
    main_window = fig.add_subplot(1,1,1)
    main_window.set_title("1720 points Full-Connected \n because of the too large numbers of points ,we ignore the lines between them")
    for i in range(size):
        a[i] = random.randint(1,1000)
        b[i] = random.randint(1,1000)
        print(i)
        plt.scatter(a[i],b[i],color='b',marker='o',s=3)
    plt.show()
if __name__ == "__main__":
    draw_points(points_x,points_y,1720)
