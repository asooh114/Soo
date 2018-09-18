void jetplot(){

  TFile * f_1 = new TFile("histo_jet_ZZ.root");

  TH1F * h_1 = (TH1F*) f_1->Get("h_MET");
  TH1F * h_2 = (TH1F*) f_1->Get("h_jet_number");
  
  h_1->GetXaxis()->SetTitle("MET of Jets");
  h_1->GetYaxis()->SetTitle("Events");

  h_2->GetXaxis()->SetTitle("Number of Jets");
  h_2->GetYaxis()->SetTitle("Events");    

  THStack hs("hs","Missing Transvere Energy of Jets");
  // TH1F * h_1 = new TH1F("h_1",";MET of Jets;Events",100,0,1);
  h_1->SetFillColor(kBlue); 
  hs.Add(h_1);

  THStack hs1("hs1","Number of Jets");
  //TH1F * h_2 = new TH1F("h_2", ";Number of Jets;Events",100,0,1);
  h_2->SetFillColor(kBlue);
  hs1.Add(h_2);

 // h_1->SetFillColor(kBlue);
  TCanvas *c = new TCanvas("c1","c1",800,600);
  c->Divide(1,2);

  c->cd(1);
  hs.Draw("hist");
  hs.SetMinimum(10);
  hs.SetMaximum(1000000000);

  TLegend *l1 = new TLegend(0.68,0.84,0.68,0.84);
  l1->AddEntry(h_1,"ZZ","F");

  l1->SetTextSize(0.025);
  l1->SetFillColor(0);
  l1->SetLineColor(0);
  l1->Draw();

  c->cd(2);
  hs1.Draw("hist");
  hs1.SetMinimum(0);
  hs1.SetMaximum(10);

  TLegend *l2 = new TLegend(0.68,0.84,0.68,0.84);
  l2->AddEntry(h_2,"ZZ","F");

  l2->SetTextSize(0.025);
  l2->SetFillColor(0);
  l2->SetLineColor(0);
  l2->Draw();

  return c;

  //gROOT->GetListOfCanvases()->Draw();
  //c->Print("jet_final.pdf");

  /*c1->SetLogy();
  hs.Draw("hist");
  hs.SetMinimum(10);
  hs.SetMaximum(1000000000);

  TLegend *l1 = new TLegend(0.68,0.84,0.68,0.84);
  l1->AddEntry(h_1,"ZZ","F");

  l1->SetTextSize(0.025);
  l1->SetFillColor(0);
  l1->SetLineColor(0);
  l1->Draw();


  //h_2->SetFillColor(kBlue);
  //TCanvas *c2 = new TCanvas("c2","c2",800,600);

  //c2->SetLogy();
  hs1.Draw("hist");
  hs1.SetMinimum(0);
  hs1.SetMaximum(10);

  TLegend *l2 = new TLegend(0.68,0.84,0.68,0.84);
  l2->AddEntry(h_2,"ZZ","F");

  l2->SetTextSize(0.025);
  l2->SetFillColor(0);
  l2->SetLineColor(0);
  l2->Draw();

  hs.GetXaxis()->SetTitle("MET");
  hs.GetYaxis()->SetTitle("Events");
  hs1.GetXaxis()->SetTitle("Number of Jets");
  hs1.GetYaxis()->SetTitle("Events");
 
  
 *TH1F* h=new TH1F("h", "MET of Jets;MET of Jets;Events", 100, 0, 1);
  hs.GetXaxis()->SetTitle("MET of Jets");
  hs.GetYaxis()->SetTitle("Events");
 
 // TH1F* h1=new TH1F("h1", ";Number of Jets;Events", 100, 0, 1);
  hs1.GetXaxis()->SetTitle("Number of Jets");
  hs1.GetYaxis()->SetTitle("Events");
 */
 
  gROOT->GetListOfCanvases()->Draw();
  c->Print("jet_final.pdf");

}

