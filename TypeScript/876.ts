// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}

let head: ListNode = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, null)))));

function middleNode(head: ListNode | null): ListNode | null {
    let middle: ListNode | null = head;
    let end: ListNode | null = head;

    while (end && end.next) {
        middle ? middle = middle.next : null; 
        end = end.next.next;
    }

    console.log(middle);
    return middle;
};

middleNode(head);
