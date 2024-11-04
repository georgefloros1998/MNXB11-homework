#include "Momentum.h"

void read(){
    // Initialize your object
    Momentum *momentum{nullptr};
    // Open your file
    auto file = TFile::Open("tree_file.root");
    // Get your tree
    TTree *tree = static_cast<TTree*>(file->Get("tree"));
    // Remember to set the branch address
    tree->SetBranchAddress("momentum", &momentum);
    // Get the number of entries
    Long64_t N = tree->GetEntries();
    // TH2 filled with px and py
    TH2F *h2 = new TH2F("h2", "Px - Py; Px; Py", 100, -0.1, 0.1, 100, -0.1, 0.1);
    // Loop over all tree entries    
    for (Int_t i{0}; i<N; i++){
        tree->GetEntry(i);
        Double_t Px = momentum->Getpx();
        Double_t Py = momentum->Getpy();
        h2->Fill(Px, Py);
    }
    TCanvas* c1 = new TCanvas("c1", "Momentum Plots", 800, 600);
    c1->Divide(2, 1);
    c1->cd(1);
    h2->Draw("LEGO2");

    // Use of TTree::Draw to draw a scatter plot of px*py vs pz
    c1->cd(2);
    tree->Draw("px*py : pz >> h(100, -0.08, 0.08, 100, -0.0015, 0.0015)","momentum->magnitude() < 0.05","colz");
    
    // If I wanted the same histogram as h2 but with TTree::Draw
    //tree->Draw("py : px >> h(100, -0.1, 0.1, 100, -0.1, 0.1)","momentum->magnitude() > 0","colz");

    // Clean up
    // file->Close(); // Doesn't work with this
    delete momentum;
    // delete file; // Doesn't work with this
}