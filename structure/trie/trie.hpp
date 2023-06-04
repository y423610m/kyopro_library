#pragma once

template< int char_size >
struct TrieNode {
    int val = -1;//この頂点の値
    int parent = -1;//親の頂点番号
    int depth = 0;//何文字目か．空文字を0とする．1文字なら1．
    int children[char_size];//次の文字の頂点番号
    int shared = 0;//この頂点を通った文字列がいくつあるか．
    vector< int > accept;//この頂点が末端である文字列のid

    TrieNode(int val, int parent, int depth) : val(val), parent(parent), depth(depth), shared(0) {
        memset(children, -1, sizeof(children));
    }
};

template< int char_size, int margin >
struct Trie {
    using Node = TrieNode< char_size >;

    vector< Node > nodes;
    int root;

    Trie() : root(0) {
        nodes.push_back(Node(-1, -1, 0));
    }

    void update_direct(int node, int id) {
        nodes[node].accept.push_back(id);
    }

    void update_child(int node, int child, int id) {
        ++nodes[node].shared;
    }

    int insert(const string &str, int str_index, int node_index, int id) {
        //引数:文字列，文字列の何文字目からか，ノードの開始点，文字列の番号
        if(str_index == str.size()) {//末尾まで来た
            update_direct(node_index, id);
            return node_index;
        } else {
            const int c = str[str_index] - margin;
            if(nodes[node_index].children[c] == -1) {
                nodes[node_index].children[c] = (int) nodes.size();
                nodes.push_back(Node(c, node_index, nodes[node_index].depth+1));
            }
            update_child(node_index, nodes[node_index].children[c], id);
            return insert(str, str_index + 1, nodes[node_index].children[c], id);
        }
    }

    int insert(const string &str, int id) {
        return insert(str, 0, 0, id);
    }

    int insert(const string &str) {
        return insert(str, nodes[0].shared);
    }

    void query(const string &str, const function< void(int) > &f, int str_index, int node_index) {
        for(auto &idx : nodes[node_index].accept) f(idx);
        if(str_index == str.size()) {
            return;
        } else {
            const int c = str[str_index] - margin;
            if(nodes[node_index].children[c] == -1) return;
            query(str, f, str_index + 1, nodes[node_index].children[c]);
        }
    }

    void query(const string &str, const function< void(int) > &f) {
        query(str, f, 0, 0);
    }

    int count() const {
        return (nodes[0].shared);
    }

    int size() const {
        return ((int) nodes.size());
    }

    //新たに構築せず既にあるところのみを探す．最終的な頂点の深さと入力文字の長さが等しければ存在する．
    int find(const string& str, int p=0){
        for(int i=0;i<str.size();i++){
            const int c = str[i] - margin;
            if(nodes[p].children[c]==-1) return p;
            p = nodes[p].children[c];
        }
        return p;
    }

    //新たに構築するが，sharedは更新しない ．
    int proceed(const string& str, int p = 0){
        for(int i=0;i<str.size();i++){
            const int c = str[i] - margin;
            if(nodes[p].children[c]==-1){
                nodes[p].children[c] = (int) nodes.size();
                nodes.push_back(Node(c, p, nodes[p].depth+1));
            }
            p = nodes[p].children[c];
        }
        return p;
    }

    //最長共通接頭辞の頂点番号
    int lcp_id(const string& l, const string& r){
        int idl = proceed(l);
        int idr = proceed(r);
        while(nodes[idl].depth>nodes[idr].depth) idl = nodes[idl].parent;
        while(nodes[idl].depth<nodes[idr].depth) idr = nodes[idr].parent;
        while(idl!=idr){
            idl = nodes[idl].parent;
            idr = nodes[idr].parent;
        }
        return idl;
    }

    //最長共通接頭辞の長さ
    int lcp_len(const string& l, const string& r){
        return nodes[lcp_id(l,r)].depth;
    }

    //最長共通接頭辞の具体例
    string lcp_string(const string& l, const string& r){
        return create_string(lcp_id(l, r));
    }

    //文字列作る
    string create_string(int id){
        if(id<0||nodes.size()<=id) return string();
        string ret;
        int p = id;
        while(p!=0){
            ret += margin+nodes[p].val;
            p = nodes[p].parent;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    //k番目の値を探す．0-indexed
    int Kth_element(int K){
        K++;
        if(nodes[0].shared<K) return -1;
        int sum = 0;
        int p = 0;
        int cnt = 4;
        while(cnt--){
            sum += nodes[p].accept.size();
            if(sum>=K) return p;
            for(int i=0;i<char_size;i++){
                if(nodes[p].children[i]==-1) continue;
                if(sum+nodes[nodes[p].children[i]].shared+nodes[nodes[p].children[i]].accept.size()<K){
                    sum += nodes[nodes[p].children[i]].shared + nodes[nodes[p].children[i]].accept.size();
                }
                else{
                    p = nodes[p].children[i];
                    break;
                }
            }
        }
        return p;
    }

    //strが辞書順何番目か
    int is_Kth(const string& str){
        int sum = 0;
        int p = 0;
        for(int i=0;i<str.size();i++){
            const int c = str[i] - margin;
            for(int j=0;j<c;j++) if(nodes[p].children[j]!=-1) sum += nodes[nodes[p].children[j]].shared;
            sum += nodes[p].accept.size();
            if(nodes[p].children[c]==-1) return sum;
            p = nodes[p].children[c];
        }
        return sum;
    }

    //一つ前後の文字列
    //見つけるまで戻ったら，あとは進み続けるだけ．
    int prev(const string& str){
        return 0;
    }

    //見つけるまで戻ったら，あとは進み続けるだけ．
    int next(const string& str){
        return 0;
    }

    //nodes[i]にアクセス
    TrieNode<char_size>& operator[](int i){
        return nodes[i];
    }

/*
    Trie<26, 'a'> tr;
    id[i] = tr.insert(S[i]);//追加．第二引数に文字列のidを指定もできる（S[i]のi）
    引数:文字列，文字列の何文字目からか，ノードの開始点，文字列の番号
    id = tr.lcp_id(s[i], s[j]);//共通接頭辞の末尾id
    len = tr.lcp_len(s[i], s[j]);//共通接頭辞の長さ
    t = tr.lcp_string(s[i], s[j]);//共通接頭辞返す
    t = tr.create_string(id);//idまでの文字列返す
    id = tr.find(S[i]);//構築せず，既存で進めるだけ進む．depthと文字列の長さが等しければ，構築済み．
    id = tr.Kth_element(k);//insertされた要素のうち，辞書順k番目の要素の末尾id.0-indexed
    k = tr.is_Kth(s[i]);//もしinsertされたら辞書順何番目か？
    int shared = tr[id].shared;//いくつの文字列がその頂点通ったか．その頂点で終わっていたら加算されていない．
    vector<int>& accept = tr[id].accept;//その頂点で終わった文字列のid．
    //insert以外は加算しない．
    //findは構築もしない
    //その他は構築だけする．

    //中身を辿るとき
    p = tr.proceed(str);
    while(p!=0){
        p = tr[p].parent;
        //val, parent, children[char_size], depth, shared, vector::accept
    }
*/
};
