 #include <iostream>
 using namespace std;

 void multiple_pointer()
 {
    const int row = 3;
    const int col = 5;

    const int s2da[row][col] = 
    {
        {1,   2,  3,  4, 5},
        {6,   7,  8,  9, 10},
        {11, 12, 13, 14, 15}
    };

    // 이중 포인터의 row 크기 설정
    int **matrix = new int*[row];

    // 이중 포인터의 col 크기 설정
    for (int r = 0; r < row; r++)
        matrix[r] = new int[col];
    
    // s2da 에서 복사
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            matrix[r][c] = s2da[r][c];

    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++)
            cout << matrix[r][c] << " ";
        cout << endl;
    }

    // delete : 생성의 역순
    for (int r = 0; r < row; r++)
        delete [] matrix[r]; // delete array를 하겠다. 어떤거? matrix[r] 에 해당하는거.
    delete [] matrix;

    // 근데 사실, 포인터 연산을 고려하면 위의 이중은 1중으로 바꿀 수 있어
    // 1자로 쭉 폈다고 생각하면 돼
    int *matrix2 = new int[row * col];
    
    // 복사하기
    // col * r : 한 줄에 col 개의 item
    //           다음 줄은, col 개의 item 수를 더한거에서 +1씩 진행
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            matrix2[c + col * r] = s2da[r][c]; 

    // 출력하기
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
            cout << matrix2[c + col * r] << " ";
        cout << endl;
    }


    delete [] matrix2;
    

 }