class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n/2;

        int leftsum = 0, rightsum = 0;
        int leftQ = 0, rightQ = 0;

        // FIRST HALF
        for(int i = 0; i < mid; i++){
            if(num[i] == '?')
                leftQ++;
            else
                leftsum += num[i] - '0';
        }

        // SECOND HALF
        for(int i = mid; i < n; i++){
            if(num[i] == '?')
                rightQ++;
            else
                rightsum += num[i] - '0';
        }

        // IF ODD ? = ALICE DEFINETLY WINS
        if((leftQ + rightQ) % 2 != 0)
            return true;

        // IF EVEN ? = BOTH BOB AND ALICE HAVE CHANCE TO WIN
        return leftsum - rightsum != 
        9 * (rightQ - leftQ) / 2;
    }
};


        //                  LC 1927
        //                SUM GAME
        //                    │
        //      ┌─────────────┴─────────────┐
        //      │                           │
        //   Alice                        Bob
        // goes first                 goes second
        //      │                           │
        //      └─────────────┬─────────────┘
        //                    │
        //              Replace '?'
        //              with 0–9
        //                    │
        //             ┌──────┴──────┐
        //             │             │
        //       ODD number      EVEN number
        //          of ?              of ?
        //             │             │
        //             ↓             ↓
        //       Alice gets      Alice + Bob
        //       final move       can respond
        //             │             │
        //             ↓             ↓
        //      Alice wins       Need to check
        //             │             │
        //             │       ┌─────┴─────┐
        //             │       │           │
        //             │   Can Bob       Can't Bob
        //             │   balance?     balance?
        //             │       │           │
        //             │       ↓           ↓
        //             │     Bob wins   Alice wins
        //             │
        //             └────────────────────────────


//               EVEN ?
//                  │
//        ┌─────────┼─────────┐
//        │         │         │
//    leftSum   rightSum   leftQ/rightQ
//        │         │         │
//        └─────────┴─────────┘
//                  │
//                  ↓
//         Existing difference
                 
//         leftSum - rightSum
//                  │
//                  │
//                  ↓
//        Unmatched ? compensation
                 
//        9 × (rightQ-leftQ) / 2
//                  │
//                  ↓
//             COMPARE
//           ┌──────┴──────┐
//           │             │
//         equal        not equal
//           │             │
//           ↓             ↓
//        Bob wins      Alice wins