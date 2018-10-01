void ana(){

  double lumi = 41529;
  TString filename = "ZZ";
  bool data = false;

  TFile fileIn(Form("%s.root", filename.Data()) ); 

  TH1F * EventInfo = (TH1F*) fileIn.Get("fcncLepJets/EventInfo");
  double scale = 1;
  if ( data ){
    scale = 1;
  }else{
    double xsection = 16.523;
    double nTotal = EventInfo->GetBinContent(2);
    scale = xsection * lumi / nTotal;
  }

  TTree* theTree = nullptr;
  TTreeReader theReader("fcncLepJets/tree",&fileIn);
  TTreeReaderValue<Int_t> channel(theReader, "channel");
  TTreeReaderValue<Float_t> MET(theReader, "MET");
  TTreeReaderValue<Float_t> lepton_pt(theReader, "lepton_pt");
  TTreeReaderValue<Float_t> lepton_eta(theReader, "lepton_eta");
  TTreeReaderValue<Float_t> lepton_phi(theReader, "lepton_phi");
  TTreeReaderValue<Float_t> lepton_e(theReader, "lepton_e");
  TTreeReaderArray<float> jet_pt(theReader, "jet_pt");
  TTreeReaderArray<float> jet_eta(theReader, "jet_eta");
  TTreeReaderArray<float> jet_phi(theReader, "jet_phi");
  TTreeReaderArray<float> jet_e(theReader, "jet_e");
  TTreeReaderArray<float> jet_deepCSV(theReader, "jet_deepCSV");
  TTreeReaderValue<Int_t> jet_number(theReader, "jet_number");

  TFile * output = new TFile(Form("histo0_%s.root", filename.Data()),"recreate");

  TH1F * h_MET = new TH1F("h_MET","MET",240,0,240);
  TH1F * h_MET_step2 = new TH1F("h_MET_step2","MET",240,0,240);
  TH1F * h_MET_step3 = new TH1F("h_MET_step3","MET",240,0,240);
//  TH1F * h_MET_step2 = new TH1F("h_MET_step2","h_MET_step2",120,0,120);
  TH1F * h_njet = new TH1F("h_njet","Jet Multiplicity",10,0,10);
  TH1F * h_nbjet_step2 = new TH1F("h_nbjet_step2","b Jet Multiplicity",10,0,10);

  int nevents = 0;
  while(theReader.Next()){

    TLorentzVector muon;
    muon.SetPtEtaPhiE( *lepton_pt, *lepton_eta, *lepton_phi, *lepton_e);
 
    TLorentzVector jet;
    int nbjet = 0; 
    for(int iJet=0; iJet<jet_pt.GetSize(); ++iJet){
      jet.SetPtEtaPhiE( jet_pt[iJet], jet_eta[iJet], jet_phi[iJet], jet_e[iJet] );
      if (jet_deepCSV[iJet] > 0.8){
        nbjet++;
      }
    }
    if( *channel == 0 && muon.Pt() > 20 && abs(muon.Eta()) < 2.1){

      float met = *MET;
     // h_MET->Fill(met, scale);
      
      int njet = *jet_number;
      h_njet->Fill(njet, scale);

      if ( njet > 0){
        h_MET->Fill(met, scale);
        }
 
      if( njet > 3){
        h_MET_step2->Fill(met, scale);
        h_nbjet_step2->Fill(nbjet, scale);
         if (nbjet > 1){
           h_MET_step3->Fill(met, scale);
         }
      } 

       

    }     

    nevents++;
  }

  //TCanvas *c_MET = new TCanvas("c_MET","c_MET",1);
  //h_MET->SetStats(0);
  //h_MET->Draw();
  //c_MET->Print(Form("c_MET_%s.pdf", filename.Data()));

  output->Write();
  output->Close();

}

