void jetana(){

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
  TTreeReaderArray<float> jet_pt(theReader, "jet_pt");
  TTreeReaderArray<float> jet_eta(theReader, "jet_eta");
  TTreeReaderArray<float> jet_phi(theReader, "jet_phi");
  TTreeReaderArray<float> jet_e(theReader, "jet_e");
  TTreeReaderValue<Int_t> jet_number(theReader, "jet_number");

  TFile * output = new TFile(Form("histo_jet_%s.root", filename.Data()),"recreate");

  TH1F * h_MET = new TH1F("h_MET","h_MET",240,0,240);
  //TH1F * h_MET_step2 = new TH1F("h_MET_step2","h_MET_step2",120,0,120);
  h_MET->GetXaxis()->SetTitle("MET of Jets");
  h_MET->GetYaxis()->SetTitle("Events");

  TH1F * h_jet_number = new TH1F("h_jet_number","h_jet_number",10,0,10);
  h_jet_number->GetXaxis()->SetTitle("Number of Jets");
  h_jet_number->GetYaxis()->SetTitle("Events");

  int nevents = 0;
      while(theReader.Next()){
 
          TLorentzVector jet;
          for(int iJet=0; iJet<jet_pt.GetSize(); ++iJet){
	    jet.SetPtEtaPhiE( jet_pt[iJet], jet_eta[iJet], jet_phi[iJet], jet_e[iJet] );
	  }

    if( *channel == 0 && jet.Pt() > 20 && abs(jet.Eta()) < 2.1){

      float met = *MET;
      h_MET->Fill(met, scale);
      
      int num = *jet_number;
      h_jet_number->Fill(num, scale); 
    }
   
      nevents++;
  }

  //TCanvas *c_MET = new TCanvas("c_MET","c_MET",1);
  //h_MET->SetStats(0);
  //h_MET->Draw();
  //c_MET->Print(Form("c_MET_%s.pdf", filename.Data()));
  
  output->Write("h_MET");
  output->Write("h_jet_number");
  output->Close();

}
