import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import ConvexHull

def plot_convex_polygon(points, color, label):
    # Calculate convex hull using scipy's ConvexHull
    hull = ConvexHull(points)
    
    # Plot the convex hull
    for simplex in hull.simplices:
        plt.plot(points[simplex, 0], points[simplex, 1], color)

    plt.scatter(points[:, 0], points[:, 1], color=color, label=label)
    for i, (x, y) in enumerate(points):
        plt.annotate(f"({x:.2f}, {y:.2f})", (x, y), textcoords="offset points", xytext=(0,5), ha='center')
def main():
    file_path1 =  r'C:\Users\ASUS\Downloads\Sample io\Sample i_o\Task-1\i_o-3\out.txt'
    #input("Enter the path to the first points file: ")
    #file_path2 = r'D:\L1T2\Code DSA\myOut.txt'
    #input("Enter the path to the second points file: ")
    
    try:
        with open(file_path1, 'r') as file1:#, open(file_path2, 'r') as file2:
            lines1 = file1.readlines()
            #lines2 = file2.readlines()
            
            points1 = [list(map(float, line.strip().split())) for line in lines1]
            #points2 = [list(map(float, line.strip().split())) for line in lines2]
            
            points1 = np.array(points1)
            #points2 = np.array(points2)
            
            plt.figure(figsize=(8, 6))
            
            # Plot the convex polygons
            plot_convex_polygon(points1, 'blue', 'Polygon 1')
           # plot_convex_polygon(points2, 'orange', 'Polygon 2')
            
            # Highlight differences
            hull1 = ConvexHull(points1)
            #hull2 = ConvexHull(points2)
            
            # Convert simplex arrays to tuples before creating the set
            #diff_lines = set(tuple(simplex) for simplex in hull1.simplices) ^ set(tuple(simplex) for simplex in hull2.simplices)
            
            # Plot differences as red lines
            #for simplex in diff_lines:
            #plt.plot(points1[simplex, 0], points1[simplex, 1], 'r--')
            #    plt.plot(points2[simplex, 0], points2[simplex, 1], 'r--')
            
            plt.xlabel('X')
            plt.ylabel('Y')
            plt.title('From out.txt')
            plt.legend()
            plt.grid()
            plt.show()
            
            # #if len(diff_lines) == 0:
            #     print("The convex polygons are identical.")
            # else:
            #     print("The convex polygons are not identical.")
            
    except FileNotFoundError:
        print("File not found.")

if __name__ == "__main__":
    main()
