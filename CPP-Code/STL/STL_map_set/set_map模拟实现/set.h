#include "RBTree.h"
namespace phw {
    template<class K>
    class set {
        //用于比较方式
        struct SetKeyOfT {
            const K &operator()(const K &key) {
                return key;
            }
        };

    public:
        //typename告诉编译器iterator是一个类型，而不是一个成员变量
        typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
        typedef typename RBTree<K, K, SetKeyOfT>::reverse_iterator reverse_iterator;//反向迭代器

        iterator begin() {
            return _t.begin();
        }

        iterator end() {
            return _t.end();
        }

        reverse_iterator rbegin() {
            return _t.rbegin();
        }
        reverse_iterator rend() {
            return _t.rend();
        }

        pair<iterator, bool> Insert(const K &key) {
            return _t.Insert(key);
        }

        //删除函数
        void erase(const K &key) {
            _t.Erase(key);
        }
        //查找函数
        iterator find(const K &key) {
            return _t.Find(key);
        }
        void InOrder() {
            _t.InOrder();
        }

    private:
        RBTree<K, K, SetKeyOfT> _t;//封装的红黑树 ，第二个K是没用的，为的是匹配map
    };
}// namespace phw
