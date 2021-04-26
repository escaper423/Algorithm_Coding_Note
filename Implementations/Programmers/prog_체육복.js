function solution(n, lost, reserve) {
    var answer = 0;
    
    let newLost = lost.filter(l => !reserve.includes(l)).sort((a,b) => a - b);
    let newReserve = reserve.filter(r => !lost.includes(r)).sort((a,b) => a -b);
    
    let p1 = 0, p2 = 0;
    while(p1 < newLost.length && p2 < newReserve.length){
        if (Math.abs(newLost[p1] - newReserve[p2]) == 1){
            p1++; p2++; answer++;
        }
        else{
            if (newLost[p1] < newReserve[p2]){
                p1++;
            }
            else{
                p2++;
            }
        }
    }
    return n - newLost.length + answer;
}
