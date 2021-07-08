//problem URL: https://leetcode.com/problems/relative-sort-array/
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let m = new Map;
    let res = [];
    arr1.forEach(elem => {
        if (m.get(elem) === undefined){
            m.set(elem,1);
        }
        else{
            m.set(elem,m.get(elem) + 1);
        }
    });
    
    arr2.forEach(elem => {
        const iter = m.get(elem);
        for(var i = 0; i < iter; i++){
            res.push(elem);
        }
        m.delete(elem);
    });
    
    m = new Map([...m].sort((a,b) => (a[0] - b[0])));

    const mapIter = m[Symbol.iterator]()
    for (const i of mapIter){
        for(var d = 0; d < i[1]; d++)
            res.push(i[0]);
    }
    
    return res;
};
