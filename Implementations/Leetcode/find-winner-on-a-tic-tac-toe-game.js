/**
 * @param {number[][]} moves
 * @return {string}
 */
//problem URL: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
var chk = function(board, winner){
    //horizontal check
    for(let i = 0; i < 3; i++){
        let symbol = board[i][0];
        if (symbol === " ")
            continue;
            
        
        let hasWinner = true;
        for(let h = 1; h < 3; h++){
            if (board[i][h] != symbol){
                hasWinner = false;
                break;
            }
        }
        
        if (hasWinner){
            winner.winner = symbol;
        }
    }
    
    //vertical check
    for(let i = 0; i < 3; i++){
        let symbol = board[0][i];
        if (symbol === " ")
            continue;
        
        let hasWinner = true;
        for(let v = 1; v < 3; v++){
            if (board[v][i] != symbol){
                hasWinner = false;
                break;
            }
        }
        
        if (hasWinner){
            winner.winner = symbol;
        }
    }
    
    //diagonal check
    let hasWinner = true;
    let symbol = board[0][0];
    for(let i = 1; i < 3; i++){
        if (symbol === " "){
            hasWinner = false;
            break;
        }
            
        
        if(symbol != board[i][i]){
            hasWinner = false;
            break;
        }
    }
    
    if (hasWinner){
        winner.winner = symbol;
    }
    
    symbol = board[0][2];
    hasWinner = true;
    for(let i = 1; i < 3; i++){
        if (symbol === " "){
            hasWinner = false;
            break;
        }
            
        
        if(symbol != board[i][2-i]){
            hasWinner = false;
            break;
        }
    }
    
    if (hasWinner){
        console.log(winner)
        winner.winner = symbol;
    }
}

var tictactoe = function(moves) {
    let winner = {winner: ""};
    let board = new Array(3).fill(" ").map(() => new Array(3).fill(" "));
    let cnt = 0;
    
    for(let [y, x] of moves){
        if (cnt%2 === 0){
            board[y][x] = "X" 
        }
            
        else{
            board[y][x] = "O" 
        }
        cnt++;
    }
    
    chk(board,winner);
    
    if (winner.winner === "X")
        return "A"
    else if (winner.winner === "O")
        return "B"
    else if (moves.length >= 9)
        return "Draw"
    else
        return "Pending"
    
};
