   int** visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[m];
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    
    
    
    for(int i=0;i<n;i++){
        delete [] visited[i];
    }
    delete [] visited;