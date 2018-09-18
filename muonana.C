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

  TFile * output = new TFile(Form("histo_%s.root", filename.Data()),"recreate");

  TH1F * h_MET = new TH1F("h_MET","h_MET",240,0,240);
//  TH1F * h_MET_step2 = new TH1F("h_MET_step2","h_MET_step2",120,0,120);

  int nevents = 0;
  while(theReader.Next()){

    TLorentzVector muon;
    muon.SetPtEtaPhiE( *lepton_pt, *lepton_eta, *lepton_phi, *lepton_e);
 
    if( *channel == 0 && muon.Pt() > 20 && abs(muon.Eta()) < 2.1){

      float met = *MET;
      h_MET->Fill(met, scale);

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

