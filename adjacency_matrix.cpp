#include<iostream>
using namespace std;
static const int N = 100;

// 入力が 5 -> n
//       1 2 4 5 -> u(頂点) k(出次数) v1(頂点) v2(頂点)
//       4 1 1
//       5 1 1
int main() {
    int M[N][N]; // 0のオリジナル行列 int p[10];でpという10要素の配列を生成する意味になる
    int n, u, k, v; // n(頂点数) u(頂点) k(出次数) v1(頂点) v2(頂点)

    cin >> n; //　頂点数を入力

    // まず0で初期化された行列を作成する
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) M[i][j] = 0;
    }

    // 戦略として0を1に上書きしてやることで隣接行列を作成する
    for ( int i = 0; i < n; i++ ) {
        cin >> u >> k;
        u--; // 頂点の番号を配列のインデックスに変換するために1引く
        for ( int j = 0; j < k; j++ ) { // 出次数kの回数だけループして頂点の場所を1に変換する
            cin >> v; // v が複数ある場合ループによって一個ずつ処理されていく(出次数の回数分)
            v--; // 頂点の番号を配列のインデックスに変換するために1引く
            M[u][v] = 1; // uとvの間にエッジを追加する。
        }
    }

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( j ) cout << " "; // jが0(初期状態)なら" "は無視
            cout << M[i][j]; // 行を出力 n = 5 なら M[0][0]~M[0][4]をM[4][0]~M[4][4]まで出力する
        }
        cout << endl;
    }

    return 0;
}