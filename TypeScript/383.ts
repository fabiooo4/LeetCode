let ransomNote: string = "aa";
let magazine: string = "aab";

function canConstruct(ransomNote: string, magazine: string): boolean {
    let magazineHash: Map<string, number> = new Map<string, number>();

    for (let char of magazine) {
        let m: string = char;
        let count: number = magazineHash.get(m) || 0;
        magazineHash.set(m, count + 1);
    }

    for (let char of ransomNote) {
        let n: string = char;
        let count: number = magazineHash.get(n) || 0;

        if (count == 0) {
            return false;
        }

        magazineHash.set(n, count - 1);
    }

    return true;
};
console.log(canConstruct(ransomNote, magazine));
canConstruct(ransomNote, magazine);
