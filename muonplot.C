void plot(){

  TFile * f_1 = new TFile("selected_muo/histo_SingleElectron_Run2017.root");
  TFile * f_2 = new TFile("selected_muo/histo_SingleMuon_Run2017.root");
  TFile * f_3 = new TFile("selected_muo/histo_DYJets_v2.root");
  TFile * f_4 = new TFile("selected_muo/histo_SingleTop_s.root");
  TFile * f_5 = new TFile("selected_muo/histo_SingleTop_t.root");
  TFile * f_6 = new TFile("selected_muo/histo_SingleTop_tW.root");
  TFile * f_7 = new TFile("selected_muo/histo_SingleTbar_t.root");
  TFile * f_8 = new TFile("selected_muo/histo_SingleTbar_tW.root");
  TFile * f_9 = new TFile("selected_muo/histo_TTHad_powheg.root");
  TFile * f_10 = new TFile("selected_muo/histo_ttHTobb.root");
  TFile * f_11 = new TFile("selected_muo/histo_ttHToNonbb.root");
  TFile * f_12 = new TFile("selected_muo/histo_TTLL_powheg.root"); //need to check
  TFile * f_13 = new TFile("selected_muo/histo_TT_powheg_signal.root");
  TFile * f_14 = new TFile("selected_muo/histo_TT_powheg_ttother.root");
  TFile * f_15 = new TFile("selected_muo/histo_TTWJetsToLNu_PSweight.root"); //small
  TFile * f_16 = new TFile("selected_muo/histo_TTWJetsToQQ.root"); //contribution is small
  TFile * f_17 = new TFile("selected_muo/histo_TTZToLLNuNu.root"); //small
  TFile * f_18 = new TFile("selected_muo/histo_TTZToQQ.root"); //small
  TFile * f_19 = new TFile("selected_muo/histo_W1JetsToLNu.root");
  TFile * f_20 = new TFile("selected_muo/histo_W2JetsToLNu.root");
  TFile * f_21 = new TFile("selected_muo/histo_W3JetsToLNu.root");
  TFile * f_22 = new TFile("selected_muo/histo_W4JetsToLNu.root");
  TFile * f_23 = new TFile("selected_muo/histo_WW.root");
  TFile * f_24 = new TFile("selected_muo/histo_WZ.root");
  TFile * f_25 = new TFile("selected_muo/histo_ZZ.root"); 
 
  TH1F * h_1 = (TH1F*) f_1->Get("h_MET");
  TH1F * h_2 = (TH1F*) f_2->Get("h_MET");
  TH1F * h_3 = (TH1F*) f_3->Get("h_MET"); 
  TH1F * h_4 = (TH1F*) f_4->Get("h_MET"); 
  TH1F * h_5 = (TH1F*) f_5->Get("h_MET");
  TH1F * h_6 = (TH1F*) f_6->Get("h_MET");
  TH1F * h_7 = (TH1F*) f_7->Get("h_MET");
  TH1F * h_8 = (TH1F*) f_8->Get("h_MET");
  TH1F * h_9 = (TH1F*) f_9->Get("h_MET");
  TH1F * h_10 = (TH1F*) f_10->Get("h_MET"); 
  TH1F * h_11 = (TH1F*) f_11->Get("h_MET");
  TH1F * h_12 = (TH1F*) f_12->Get("h_MET");
  TH1F * h_13 = (TH1F*) f_13->Get("h_MET");
  TH1F * h_14 = (TH1F*) f_14->Get("h_MET");
  TH1F * h_15 = (TH1F*) f_15->Get("h_MET");
  TH1F * h_16 = (TH1F*) f_16->Get("h_MET");
  TH1F * h_17 = (TH1F*) f_17->Get("h_MET");
  TH1F * h_18 = (TH1F*) f_18->Get("h_MET");
  TH1F * h_19 = (TH1F*) f_19->Get("h_MET");
  TH1F * h_20 = (TH1F*) f_20->Get("h_MET");
  TH1F * h_21 = (TH1F*) f_21->Get("h_MET");
  TH1F * h_22 = (TH1F*) f_22->Get("h_MET");
  TH1F * h_23 = (TH1F*) f_23->Get("h_MET");
  TH1F * h_24 = (TH1F*) f_24->Get("h_MET");
  TH1F * h_25 = (TH1F*) f_25->Get("h_MET");
  

  THStack hs("hs","Missing Transvere Energy of Muons in 2017");
  hs.Add(h_15);//ttbar
  h_4->Add(h_5);
  h_4->Add(h_6);
  h_4->Add(h_7);
  h_4->Add(h_8); //add all single top processes
  hs.Add(h_4);
  hs.Add(h_3);
  hs.Add(h_9);
  hs.Add(h_10);
  hs.Add(h_11);
  hs.Add(h_12);
  hs.Add(h_13);
  hs.Add(h_14);
  hs.Add(h_16);
  hs.Add(h_17);
  hs.Add(h_18);
  h_19->Add(h_20);
  h_19->Add(h_21);
  h_19->Add(h_22);
  hs.Add(h_19);
  hs.Add(h_23);
  hs.Add(h_24); 
  hs.Add(h_25);

  h_3->SetFillColor(kBlue);
  h_4->SetFillColor(kGreen);
  h_9->SetFillColor(kMagenta);
  h_10->SetFillColor(kAzure);
  h_11->SetFillColor(kCyan);
  h_12->SetFillColor(kViolet);
  h_13->SetFillColor(kOrange);
  h_14->SetFillColor(kPink);
  h_15->SetFillColor(kRed);
  h_16->SetFillColor(kBlueYellow);
  h_17->SetFillColor(kCherry);
  h_18->SetFillColor(kGreenPink);
  h_19->SetFillColor(kRose);
  h_23->SetFillColor(kSienna);
  h_24->SetFillColor(kYellow);
  h_25->SetFillColor(kArmy);
  TCanvas *c = new TCanvas("c","c",1);

  c->SetLogy();
  hs.Draw("hist");
  hs.SetMinimum(10);
  hs.SetMaximum(1000000000);

  h_1->Add(h_2); // muon + electron 
  h_1->SetMarkerStyle(20); 
  h_1->Draw("Psame"); 


  TLegend *l = new TLegend(1.10,0.92,0.56,0.56);
  l->AddEntry(h_1,"Data","P"); 
  l->AddEntry(h_3,"DYJets","F");
  l->AddEntry(h_19,"WJets","F");
  l->AddEntry(h_4,"Single top","F");
  //l->AddEntry(h_5,"ST_t","F");
  //l->AddEntry(h_6,"ST_tW","F");
  //l->AddEntry(h_7,"ST_tbar","F");
  //l->AddEntry(h_8,"ST_tWbar","F");
  l->AddEntry(h_9,"TT_Hadronic","F");
  l->AddEntry(h_10,"ttHTobb","F");
  l->AddEntry(h_11,"ttHToNonbb","F");
  l->AddEntry(h_12,"TTLL","F");
  l->AddEntry(h_13,"TT_Signal","F");
  l->AddEntry(h_14,"TT_other","F");
  l->AddEntry(h_15,"TTWJetsToLNu","F");
  l->AddEntry(h_16,"TTWJetsToQQ","F");
  l->AddEntry(h_17,"TTZToLLNuNu","F");
  l->AddEntry(h_18,"TTZToQQ","F");
  l->AddEntry(h_23,"WW","F");
  l->AddEntry(h_24,"WZ","F");
  l->AddEntry(h_25,"ZZ","F");
  

  l->SetTextSize(0.025);
  l->SetFillColor(0);
  l->SetLineColor(0); 
  l->Draw();

  hs.GetXaxis()->SetTitle("MET"); 
  hs.GetYaxis()->SetTitle("Events"); 
 
  c->Print("final.pdf");

}
