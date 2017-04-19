#class 3
Iterative Deletion of Dominated Strategies
---
An application: model of politics:</br>
two candidates.</br>
strategy: choose positions on a political spectrum, 10% votes of each politics.</br>
vote for closest candidate, if tie, split</br>
left wing $\bar{1}, \bar{2}, \bar{3}, \bar{4}, \bar{5}, \bar{6}, \bar{7}, \bar{8}, \bar{9}, \bar{10}$ right wing</br>
payoffs: candidates aim to __maximize share of vote__.

####2 dominate 1
*Test does 2 dominate 1?*
vs 1, $U_1(1,1)=50\% \lt U_1(2,1)=90\%, \surd$</br>
vs 2, $U_1(1,2)=10\% \lt U_1(2,2)=50\%, \surd$</br>
vs 3, $U_1(1,3)=15\% \lt U_1(2,3)=20\%, \surd$</br>
vs 4, $U_1(1,4)=20\% \lt U_1(2,4)=25\%, \surd$</br>
choosing 2 always gave me 5% more of the votes than choosing 1.</br>
conclude:

- 2 strictly dominate 1
- 9 strictly dominate 10

*What about 2 is dominated by 3?*</br>
vs 1, $u_1(2,1)=90\% \lt u_1(3,1)=85\%, \times$</br>
*But if we delete strategies 1 and 10, then does 3 dominate 2?*</br>
vs 2, $u_1(2,2)=50\% \lt u_1(3,2)=80\%, \surd$</br>
vs 3, $u_1(2,3)=20\% \lt u_1(3,3)=50\%, \surd$</br>
vs 4, $u_1(2,4)=25\% \lt u_1(3,4)=30\%, \surd$</br>
vs 5, $u_1(2,5)=30\% \lt u_1(3,5)=35\%, \surd$</br>
2 and 9 are not dominated but they are dominated once we realize 1 and 10 won't be played.

"it del" leads to deleting all except **5 and 6**.</br>
Prediction: candidate crowd the center</br>
**Median Voter Theorem**</br>
missing:</br>

1. voters are not evenly distributed in the real world
2. not voting
3. many candidates
4. position not believed(commit to policy)
5. primaries
6. high dimentions

###Different Approach: Best Response
                2/          
             L     R   
          ┌─────┬─────┐
        U │ 5,1 │ 0,2 │
     1/   ├─────┼─────┤
        M │ 1,3 │ 4,1 │
          ├─────┼─────┤
        D │ 4,2 │ 2,3 │
          └─────┴─────┘
          
U **does best against** L.</br>
M **does best against** R.</br>

Expected payoff of U, vs $(\frac{1}{2},\frac{1}{2})=(\frac{1}{2},\frac{1}{2})=(\frac{1}{2})\cdot5+(\frac{1}{2})\cdot0=2.5$</br>
Expected payoff of M, vs $(\frac{1}{2},\frac{1}{2})=(\frac{1}{2},\frac{1}{2})=(\frac{1}{2})\cdot1+(\frac{1}{2})\cdot4=2.5$</br>
Expected payoff of D, vs $(\frac{1}{2},\frac{1}{2})=(\frac{1}{2},\frac{1}{2})=(\frac{1}{2})\cdot4+(\frac{1}{2})\cdot2=3$</br>

![img](images/00.png)
