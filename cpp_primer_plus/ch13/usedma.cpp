//
// Created by 周天斌 on 2021/12/23.
//

#include <iostream>
#include "dma.h"

int main() {
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA ballon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << ballon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    // core lacksDMA中baseDMA的部分会使用基类的复制构造函数，其他的部分使用默认复制构造函数
    lacksDMA ballon2(ballon);
    cout << "Result of lacksDMA copy:\n";
    cout << ballon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    return 0;
}