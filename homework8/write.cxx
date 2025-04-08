#include "Momentum.h"

void write(Int_t nEvents=10000);

void write(Int_t nEvents) {
    // Initialize your object e.g. as a pointer
    Momentum *momentum{nullptr};
    // Create your root file
    TFile f("tree_file.root", "RECREATE");
    // Create your TTree
    TTree *tree = new TTree ("tree", "momentum tree");
    // Create the associated branches underneath
    Double_t px, py, pz;
    // I don't need branches with momentum cordinates
    // They exist as leaves in the "momentum" branch
    // If I wanted them I would have done this
    /*
    tree->Branch("px", &px);
    tree->Branch("py", &py);
    tree->Branch("pz", &pz);
    */
    // A branch with your personal object type
    tree->Branch("momentum", &momentum);
    // Create loop for filling the tree with data
    for (Int_t i{0}; i<nEvents; i++){
        // Initialize your new object
        px = gRandom->Gaus(0,.02);
        py = gRandom->Gaus(0,.02);
        pz = gRandom->Gaus(0,.02);
        momentum = new Momentum(px, py, pz);
        // Fill tree
        tree->Fill();
        // Remember to delete it again otherise you will have memory leak!
        delete momentum;
    }
    // Save the tree/file
    tree->AutoSave();
}