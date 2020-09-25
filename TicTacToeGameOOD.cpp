class TikTacToe{
public:
    vector<vector<int>> board;
    vector<int> rowSum,colSum;
    int diagSum,revDiagSum;
    int n;
    int winner=-1;
    int winCount[100000]={0},lossCount[100000]={0},drawCount[100000]={0};
    int playerId[2];
    int numMoves=0;
    //player is either 0 or 1
    //board is of size n*n
    //initial value on board is considered 0
    //player 0 move is considered -1 while player 1 move is considered to be 1;
    TikTacToe(int n, int id1, int id2){
        board.resize(n,vector<int> (n));
        rowSum.resize(n);
        colSum.resize(n);
        playerId[0]=id1;
        playerId[1]=id2;
    }

    int move(int player, int row, int column){
        if(player != 0 && player != 1) throw invalid_argument("Invalid Player");
        else if(row < 0 || column < 0 || row >= n || column >= n) throw invalid_argument("Move is out of Boundary");
        else if(board[row][column] != 0) throw invalid_argument("Square is already occupied");
        else{
            numMoves++;
            int cur;
            if(player == 0)
                cur=-1;
            else
                cur=1;
            board[row][column]=cur;
            rowSum[row]+=cur;
            colSum[column]+=cur;
            if(row == column) diagSum+=cur;
            if(row+column == n-1) revDiagSum+=cur;
            if(n == abs(rowSum[row]) || n == abs(colSum[column]) || n == abs(diagSum) || n == abs(revDiagSum)){
                winner=player;
                winCount[playerId[winner]]++;
                lossCount[playerId[winner^1]]++;
            }
            if(numMoves==n*n && winner == -1){
                drawCount[playerId[0]]++;
                drawCount[playerId[1]]++;
            }
        }
    }

    int getWinner(){
        return winner;
    }

    void getBoardStatus(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void getPlayerStats(int playerId){
        cout << "Wins: " << winCount[playerId] << "\n";
        cout << "Losses: " << lossCount[playerId] << "\n";
        cout << "Draws: " << drawCount[playerId] << "\n";
    }
};
