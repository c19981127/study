import numpy as np
z = np.ones((1720,1720))
result = np.zeros(1720)
def Degree_Centrality(m,size):
    list = np.zeros(size)
    for i in range(len(m)):
        for j in range(len(m[0])):
            list[i] += m[i][j]
    return  list
def Eigenvector_Centrality(m,size):
    X,mat = np.linalg.eig(m);
    X_array = X.tolist()
    X_max = max(X_array)
    index = X_array.index(X_max)
    temp = mat[:,index]
    return temp
def katz_Centraliy(m,x,y,size):
    temp = np.mat(np.eye(size))
    temp_temp = np.mat(np.ones((size,1)))
    katz = y * (temp - x*m.T).I * temp_temp
    print(katz)

def page_rank(m,x,y,size):
    temp = Degree_Centrality(m,1720)
    temp_array = np.zeros((size,size))
    for j in range(len(temp)):
        temp_array[j][j] = temp[j]
    temp_mat = np.mat(temp_array)
    i = np.eye(size)
    ones = np.mat(np.ones((size,1)))

    page = y * (i-x*m.T*temp_mat.I).I*ones
    return page
def Betweenness_Centrality(m,size,a,b):
    for i in range(a,size):
        for j in range(b,size):
            print(i)
            print(j)
            if i==j :
                continue
            elif m[i][j] != 1:
                for x in range(size):
                    if m[j][x] == 1 :
                        result[i]+=1
                        result[j]+=1
                        Betweenness_Centrality(m,size,i,x)
            else:
                result[i]+=1
                result[j]+=1



if __name__ == '__main__':
    Betweenness_Centrality(z,1720,0,0)
    print(result)
