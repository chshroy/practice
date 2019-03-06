#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> tr;
pii //存储的类型
null_type //无映射(低版本g++为null_mapped_type)
less<pii> //从小到大排序
rb_tree_tag //红黑树
tree_order_statistics_node_update //更新方式 
tr.insert(mp(x,y)); //插入;
tr.erase(mp(x,y)); //删除;
tr.order_of_key(pii(x,y)); //求排名 
tr.find_by_order(x); //找k小值，返回迭代器 
tr.join(b); //将b并入tr，前提是两棵树类型一样且没有重复元素 
tr.split(v,b); //分裂，key小于等于v的元素属于tr，其余的属于b
tr.lower_bound(x); //返回第一个大于等于x的元素的迭代器
tr.upper_bound(x); //返回第一个大于x的元素的迭代器
//以上所有操作的时间复杂度均为O(logn) 
