#include<iostream>
using namespace std;


/*
 alpha-beta pruning : [alpha,beta] zero-sum game
 min-max search: find the max node after the pre min node which the peer choose

 alpha 是兄弟节点能获得的最差的值, 如果节点分支中存在比alpha还小的值，那本分支就没有必要考虑了,
 因为如果选择本分支，则对手一定会选中比alpha还小的那个值, alpha的更新只能越来越大 ==> alpha节点的存在是为了cut-off兄弟节点 
 */


int alphaBeta (int depth, int alpha, int beta) {
  int score;
  cout<<"进入搜索函数"<<endl;
  if (depth == 0) {
    /*
     * 只在叶子节点进行局面评估, 棋盘的更新自然地把每个吃子信息携带到里叶子节点, 不需要在每次落子都进行局面评估
     */
    //TODO
    return; 
  }

  /*
   * alpha-beta 依赖查找顺序,如果刚开始的时候就找到最佳的走法,后面就会产生beta截断,搜索效率会提高很多，反之则效率很低
   * 所有在遍历所有节点前，先按照先验知识,为所有的节点排序，利用历史表的信息排序,
   */
  for (int i = 0; i < 10; i++) {
    //TODO 这里可以加上单步移动得
    score = -alphaBeta(depth - 1, -beta, -alpha);

    if (score >=beta) {
      /*
       * if score is higher than beta', we return beta', beta' equal -alpha ; socre = -score' , as score' > -alaph so score < aplpa

        A+B  A1+B1    if (B1 < )
       */
      return score;
    }

    if (score > alpha) {
      /*
       * update alpha , alpha is the high score which neighbor nodes can achieve
       */
      alpha = score;
    }
  }

  return alpha;
}

int g_times = 0;

/*
 × history Heuristic 
 * 浅一层的最好结果在深一层的搜索中首先被尝试,可以帮助alphaBeta搜索进行更快的剪支,所以alphaBeta在启发式的场景下搜索效率很高
 × 如何把浅一层的搜索结果记录下来？主分支，主要变例
 */
void mutipleSearch() {
  int depth = 0;
  int alpha = -MAXNUM;
  int beta = MAXNUM;
  while(g_time < 1000) {
    alphaBeta(depth++, alpha, beta);
  }
}

/*
 * 历史表启发, 如果一个走法在很多层的搜索中都被走过,且得分还不错，我们把这种走法存起来，后面搜索优先进行
 × 什么样的走法是好的走法,1:能够产生beta截断的走法 2:遍历完所有子分支，最好的走法
 × 历史表中存的值是 depth的深度的平方,历史表在每次走棋之前清0
 */
void historyHeuristic(int x,int y) {
}

/*
 * 置换表:即利用hash表把以前搜索过的局面记录下来，下次再遇到直接读取结果
 */
int main() {
  cout<<"hello world\n"<<endl;
}
















































