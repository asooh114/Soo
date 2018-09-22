void plot(){

  TFile * f_0 = new TFile("jetselected_muo/histo_jet_SingleElectron_Run2017.root");
  TFile * f_1 = new TFile("jetselected_muo/histo_jet_SingleMuon_Run2017.root");
  /*TFile * f_2 = new TFile("jetselected_muo/histo_jet_DYJets_4to50_HT70to100.root");
  TFile * f_3 = new TFile("jetselected_muo/histo_jet_DYJets_4to50_HT100to200_v2.root");
  TFile * f_4 = new TFile("jetselected_muo/histo_jet_DYJets_4to50_HT200to400.root");
  TFile * f_5 = new TFile("jetselected_muo/histo_jet_DYJets_4to50_HT400to600.root");
  TFile * f_6 = new TFile("jetselected_muo/histo_jet_DYJets_4to50_HT600toinf.root");
 */
  TFile * f_7 = new TFile("jetselected_muo/histo_jet_DYJets_v2.root");
  TFile * f_8 = new TFile("jetselected_muo/histo_jet_SingleTop_s.root");
  TFile * f_9 = new TFile("jetselected_muo/histo_jet_SingleTop_t.root");
  TFile * f_10 = new TFile("jetselected_muo/histo_jet_SingleTbar_t.root");
  TFile * f_11 = new TFile("jetselected_muo/histo_jet_SingleTop_tW.root");
  TFile * f_12 = new TFile("jetselected_muo/histo_jet_SingleTbar_tW.root"); //TTLL_powheg.root need to check
  TFile * f_13 = new TFile("jetselected_muo/histo_jet_TTHad_powheg.root");
  TFile * f_14 = new TFile("jetselected_muo/histo_jet_ttHTobb.root");
  TFile * f_15 = new TFile("jetselected_muo/histo_jet_ttHToNonbb.root"); //TTWJetsToLNu_PSweight.root small
  TFile * f_16 = new TFile("jetselected_muo/histo_jet_TTLL_powheg.root"); //TTWJetsToQQ.root contribution is small
  TFile * f_17 = new TFile("jetselected_muo/histo_jet_TT_powheg_signal.root"); //TTZToLLNuNu.root small
  TFile * f_18 = new TFile("jetselected_muo/histo_jet_TT_powheg_ttother.root"); //TTZToQQ.root small
  TFile * f_19 = new TFile("jetselected_muo/histo_jet_TTWJetsToLNu_PSweight.root");
  TFile * f_20 = new TFile("jetselected_muo/histo_jet_TTWJetsToQQ.root");
  TFile * f_21 = new TFile("jetselected_muo/histo_jet_TTZToLLNuNu.root");
  TFile * f_22 = new TFile("jetselected_muo/histo_jet_TTZToQQ.root");
  TFile * f_23 = new TFile("jetselected_muo/histo_jet_W1JetsToLNu.root");
  TFile * f_24 = new TFile("jetselected_muo/histo_jet_W2JetsToLNu.root");
  TFile * f_25 = new TFile("jetselected_muo/histo_jet_W3JetsToLNu.root"); 
  TFile * f_26 = new TFile("jetselected_muo/histo_jet_W4JetsToLNu.root");
  TFile * f_27 = new TFile("jetselected_muo/histo_jet_WW.root");
  TFile * f_28 = new TFile("jetselected_muo/histo_jet_WZ.root");
  TFile * f_29 = new TFile("jetselected_muo/histo_jet_ZZ.root");
 
  TH1F * h_0 = (TH1F*) f_0->Get("h_MET_step2");
  TH1F * h_1 = (TH1F*) f_1->Get("h_MET_step2");
  /*TH1F * h_2 = (TH1F*) f_2->Get("h_MET_step2");
  TH1F * h_3 = (TH1F*) f_3->Get("h_MET_step2"); 
  TH1F * h_4 = (TH1F*) f_4->Get("h_MET_step2"); 
  TH1F * h_5 = (TH1F*) f_5->Get("h_MET_step2");
  TH1F * h_6 = (TH1F*) f_6->Get("h_MET_step2");
  */
  TH1F * h_7 = (TH1F*) f_7->Get("h_MET_step2");
  TH1F * h_8 = (TH1F*) f_8->Get("h_MET_step2");
  TH1F * h_9 = (TH1F*) f_9->Get("h_MET_step2");
  TH1F * h_10 = (TH1F*) f_10->Get("h_MET_step2"); 
  TH1F * h_11 = (TH1F*) f_11->Get("h_MET_step2");
  TH1F * h_12 = (TH1F*) f_12->Get("h_MET_step2");
  TH1F * h_13 = (TH1F*) f_13->Get("h_MET_step2");
  TH1F * h_14 = (TH1F*) f_14->Get("h_MET_step2");
  TH1F * h_15 = (TH1F*) f_15->Get("h_MET_step2");
  TH1F * h_16 = (TH1F*) f_16->Get("h_MET_step2");
  TH1F * h_17 = (TH1F*) f_17->Get("h_MET_step2");
  TH1F * h_18 = (TH1F*) f_18->Get("h_MET_step2");
  TH1F * h_19 = (TH1F*) f_19->Get("h_MET_step2");
  TH1F * h_20 = (TH1F*) f_20->Get("h_MET_step2");
  TH1F * h_21 = (TH1F*) f_21->Get("h_MET_step2");
  TH1F * h_22 = (TH1F*) f_22->Get("h_MET_step2");
  TH1F * h_23 = (TH1F*) f_23->Get("h_MET_step2");
  TH1F * h_24 = (TH1F*) f_24->Get("h_MET_step2");
  TH1F * h_25 = (TH1F*) f_25->Get("h_MET_step2");
  TH1F * h_26 = (TH1F*) f_26->Get("h_MET_step2");
  TH1F * h_27 = (TH1F*) f_27->Get("h_MET_step2");
  TH1F * h_28 = (TH1F*) f_28->Get("h_MET_step2");
  TH1F * h_29 = (TH1F*) f_29->Get("h_MET_step2");


  THStack hs("hs","Missing Transvere Energy of Muons under the condition njet>3 in 2017");
  h_17->Add(h_18);
  hs.Add(h_17); //TTSignal+ttother
  /* h_2->Add(h_3);
  h_2->Add(h_4);
  h_2->Add(h_5);
  h_2->Add(h_6);
  h_2->Add(h_7);
  */
  hs.Add(h_7); //add all DYJets
  h_8->Add(h_9);
  h_8->Add(h_10);
  h_8->Add(h_11);
  h_8->Add(h_12);
  hs.Add(h_8); //add all single top processes
  h_13->Add(h_16);
  hs.Add(h_13); //TTLL+Hadronic
  h_14->Add(h_15);
  hs.Add(h_14); //ttHtobb+nonbb
  h_19->Add(h_20);
  h_19->Add(h_21);
  h_19->Add(h_22);
  hs.Add(h_19); //TTW~TTZ
  h_23->Add(h_24);
  h_23->Add(h_25);
  h_23->Add(h_26);
  hs.Add(h_23); //WJets
  hs.Add(h_27);
  hs.Add(h_28);
  hs.Add(h_29);


  h_7->SetFillColor(kBlue);
  h_8->SetFillColor(kGreen);
  h_13->SetFillColor(kMagenta);
  h_14->SetFillColor(kAzure);
  h_17->SetFillColor(kRed);
  h_19->SetFillColor(kViolet);
  h_23->SetFillColor(kOrange);
  h_27->SetFillColor(kPink);
  h_28->SetFillColor(kYellow);
  h_29->SetFillColor(kArmy);
  TCanvas *c = new TCanvas("c","c",1);
  /*
  h_17->SetFillColor(kCherry);
  h_18->SetFillColor(kGreenPink);
  h_19->SetFillColor(kRose);
  h_23->SetFillColor(kSienna);
  h_24->SetFillColor(kYellow);
  h_25->SetFillColor(kBlueYellow);
  */

  c->SetLogy();
  hs.Draw("hist");
  hs.SetMinimum(10);
  hs.SetMaximum(100000);

  h_1->Add(h_0); // muon + electron 
  h_1->SetMarkerStyle(20); 
  h_1->Draw("Psame"); 


  TLegend *l = new TLegend(0.62,0.62,0.84,0.86);
  l->AddEntry(h_1,"Data","P"); 
  l->AddEntry(h_7,"DYJets","F");
  l->AddEntry(h_8,"Single top","F");
  l->AddEntry(h_13,"TTother","F");
  //l->AddEntry(h_5,"ST_t","F");
  //l->AddEntry(h_6,"ST_tW","F");
  //l->AddEntry(h_7,"ST_tbar","F");
  //l->AddEntry(h_8,"ST_tWbar","F");
  l->AddEntry(h_14,"TTbar+Higs","F");
  l->AddEntry(h_17,"TTSignal","F");
  l->AddEntry(h_19,"TTV","F");
  l->AddEntry(h_23,"WJets","F");
  l->AddEntry(h_27,"WW","F");
  l->AddEntry(h_28,"WZ","F");
  l->AddEntry(h_29,"ZZ","F");
   

  l->SetTextSize(0.032);
  l->SetFillColor(0);
  l->SetLineColor(0); 
  l->Draw();

  hs.GetXaxis()->SetTitle("MET"); 
  hs.GetYaxis()->SetTitle("Events"); 
 
  c->Print("METstep2final.pdf");

}
