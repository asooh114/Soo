#define MyAnalysis_cxx
// The class definition in MyAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("MyAnalysis.C")
// Root > T->Process("MyAnalysis.C","some options")
// Root > T->Process("MyAnalysis.C+")
//

#include "MyAnalysis.h"
#include <iostream>
#include <TH1F.h>
#include <TLatex.h>

using namespace std;

void MyAnalysis::BuildEvent() {
   
   Muons.clear();
   for (int i = 0; i < NMuon; ++i) {
      MyMuon muon(Muon_Px[i], Muon_Py[i], Muon_Pz[i], Muon_E[i]);
      muon.SetIsolation(Muon_Iso[i]);
      muon.SetCharge(Muon_Charge[i]);
      Muons.push_back(muon);
   }
   
   Electrons.clear();
   for (int i = 0; i < NElectron; ++i) {
      MyElectron electron(Electron_Px[i], Electron_Py[i], Electron_Pz[i], Electron_E[i]);
      electron.SetIsolation(Electron_Iso[i]);
      electron.SetCharge(Electron_Charge[i]);
      Electrons.push_back(electron);
   }
  
   Photons.clear();
   for (int i = 0; i < NPhoton; ++i) {
      MyPhoton photon(Photon_Px[i], Photon_Py[i], Photon_Pz[i], Photon_E[i]);
      photon.SetIsolation(Photon_Iso[i]);
      Photons.push_back(photon);
   }
   
   Jets.clear();
   for (int i = 0; i < NJet; ++i) {
      MyJet jet(Jet_Px[i], Jet_Py[i], Jet_Pz[i], Jet_E[i]);
      jet.SetBTagDiscriminator(Jet_btag[i]);
      jet.SetJetID(Jet_ID[i]);
      Jets.push_back(jet);
   }
 
  
   hadB.SetXYZM(MChadronicBottom_px, MChadronicBottom_py, MChadronicBottom_pz, 4.8);
   lepB.SetXYZM(MCleptonicBottom_px, MCleptonicBottom_py, MCleptonicBottom_pz, 4.8);
   hadWq.SetXYZM(MChadronicWDecayQuark_px, MChadronicWDecayQuark_py, MChadronicWDecayQuark_pz, 0.0);
   hadWqb.SetXYZM(MChadronicWDecayQuarkBar_px, MChadronicWDecayQuarkBar_py, MChadronicWDecayQuarkBar_pz, 0.0);
   lepWl.SetXYZM(MClepton_px, MClepton_py, MClepton_pz, 0.0);
   lepWn.SetXYZM(MCneutrino_px, MCneutrino_py, MCneutrino_pz, 0.0);
   met.SetXYZM(MET_px, MET_py, 0., 0.);
   
   EventWeight *= weight_factor;
   
}

void MyAnalysis::Begin(TTree * /*tree*/) {
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
}

void MyAnalysis::SlaveBegin(TTree * /*tree*/) {
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
   h_Mmumu = new TH1F("Mmumu", "Invariant di-muon mass", 60, 60, 120);
   h_Mmumu->SetXTitle("m_{#mu#mu}");
   h_Mmumu->Sumw2();
   histograms.push_back(h_Mmumu);
   histograms_MC.push_back(h_Mmumu);
   
   h_NMuon = new TH1F("NMuon", "Number of muons", 7, 0, 7);
   h_NMuon->SetXTitle("No. Muons");
   h_NMuon->Sumw2();
   histograms.push_back(h_NMuon);
   histograms_MC.push_back(h_NMuon);
   
   h_MET = new TH1F("MET", "METTTTTT", 100, 0, 100);
   h_MET->SetXTitle("Missing transverse energy of Muons(GeV)");
   h_MET->Sumw2();
   histograms.push_back(h_MET);
   histograms_MC.push_back(h_MET);
   
   h_MET_nJets2 = new TH1F("MET_nJets2", "MET_nJets2", 100, 0, 100);
   h_MET_nJets2->SetXTitle("Missing transverse energy of Jets(GeV)");
   h_MET_nJets2->Sumw2();
   histograms.push_back(h_MET_nJets2);
   histograms_MC.push_back(h_MET_nJets2);

   h_MET_nbJets2 = new TH1F("MET_nbJets2", "MET_nbJets2", 100, 0, 100);
   h_MET_nbJets2->SetXTitle("Missing transverse energy of b Jets(GeV)");
   h_MET_nbJets2->Sumw2();
   histograms.push_back(h_MET_nbJets2);
   histograms_MC.push_back(h_MET_nbJets2);

   h_nJets = new TH1F("nJets", "nJets", 9, 0, 9);
   h_nJets->SetXTitle("Number of Jets");
   h_nJets->Sumw2();
   histograms.push_back(h_nJets);
   histograms_MC.push_back(h_nJets);
 
   h_nbJets = new TH1F("nbJets", "nbJets", 10, 0, 10);
   h_nbJets->SetXTitle("Number of bJets");
   h_nbJets->Sumw2();
   histograms.push_back(h_nbJets);
   histograms_MC.push_back(h_nbJets);


}

Bool_t MyAnalysis::Process(Long64_t entry) {
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MyAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   
   ++TotalEvents;
   
   GetEntry(entry);
   
   if (TotalEvents % 10000 == 0)
      cout << "Next event -----> " << TotalEvents << endl;
   
   BuildEvent();
   
   double MuonPtCut = 25.;
   double MuonRelIsoCut = 0.10;
   
   //   cout << "Jets: " << endl;
   //   for (vector<MyJet>::iterator it = Jets.begin(); it != Jets.end(); ++it) {
   //      cout << "pt, eta, phi, btag, id: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->IsBTagged() << ", " << it->GetJetID()
   //      << endl;
   //   }
   //   cout << "Muons: " << endl;
   //   for (vector<MyMuon>::iterator it = Muons.begin(); it != Muons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Electrons: " << endl;
   //   for (vector<MyElectron>::iterator it = Electrons.begin(); it != Electrons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Photons: " << endl;
   //   for (vector<MyPhoton>::iterator it = Photons.begin(); it != Photons.end(); ++it) {
   //      cout << "pt, eta, phi, iso: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->GetIsolation()
   //      << endl;
   //   }
   
   
   //////////////////////////////
   // Exercise 1: Invariant Di-Muon mass
   
   int N_IsoMuon = 0;
   MyMuon *muon1, *muon2;
   
   for (vector<MyMuon>::iterator jt = Muons.begin(); jt != Muons.end(); ++jt) {
      if (jt->IsIsolated(MuonRelIsoCut)) {
         ++N_IsoMuon;
         if (N_IsoMuon == 1) muon1 = &(*jt);
         if (N_IsoMuon == 2) muon2 = &(*jt);
      }
   }
   
   h_NMuon->Fill(N_IsoMuon, EventWeight);

   int nJets = 0;
   int nbJets = 0;
   for (vector<MyJet>::iterator jt = Jets.begin(); jt != Jets.end(); ++jt) {
       nJets = nJets + 1;
       MyJet *jet = &(*jt);
       bool isbtagged = jet->IsBTagged();
       if ( isbtagged )
         nbJets++ ;
   }
   //cout << "number of jets = " << nJets << endl;
   //cout << "number of b jets = " << nbJets << endl;

   double met_pt = met.Pt();
   
   if (N_IsoMuon > 0  && triggerIsoMu24) {
      if (muon1->Pt()>MuonPtCut) {
         h_Mmumu->Fill((*muon1 + *muon2).M(), EventWeight);
         h_MET->Fill(met_pt, EventWeight);   
         h_nJets->Fill(nJets, EventWeight);
         h_nbJets->Fill(nbJets, EventWeight);
         if ( nJets >= 2 ){
           h_MET_nJets2->Fill(met_pt, EventWeight);
           if ( nbJets>= 1 ){
             h_MET_nbJets2->Fill(met_pt, EventWeight);
           }

         }

      }
   }
   //////////////////////////////

   return kTRUE;
}

void MyAnalysis::SlaveTerminate() {
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   
}

void MyAnalysis::Terminate() {
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
}

