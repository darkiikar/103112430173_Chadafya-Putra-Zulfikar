#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);

    std::cout << "\n\nCHADAFYA PUTRA ZULFIKAR | IF-12-02" << std::endl;
    
    // 2) Alokasi dan Insert (Sesuai urutan gambar: G004 paling depan karena insertFirst)
    NodeParent *g4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(LP, g4);
    NodeParent *g3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(LP, g3);
    NodeParent *g2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(LP, g2);
    NodeParent *g1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(LP, g1);

    insertLastChild(g1->childs, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    insertLastChild(g2->childs, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(g2->childs, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(g3->childs, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(g4->childs, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(g4->childs, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    // 3) Print MLL
    cout << "\n--- TAMPILAN AWAL ---" << endl;
    printStrukturMLL(LP);

    // 4) Search Rating 8.0 - 8.5
    cout << "\n--- HASIL PENCARIAN RATING 8.0 - 8.5 ---" << endl;
    searchFilmByRatingRange(LP, 8.0, 8.5);

    // 5) Delete After Parent G001 (menghapus G002)
    NodeParent *deleted;
    deleteAfterParent(LP, LP.first, deleted);
    
    // 6) Print Akhir
    cout << "\n--- SETELAH DELETE G002 ---" << endl;
    printStrukturMLL(LP);

    std::cout << "\n\nPROGRAM SELESAI KING" << std::endl;

    return 0;
}