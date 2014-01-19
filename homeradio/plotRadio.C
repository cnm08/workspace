#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLegend.h"

void plotRadio(){


TGraphErrors *MyGraph1000000 = new TGraphErrors("decay1000000.dat", "\%lg \%lg");
MyGraph1000000->SetMarkerColor(kRed);
MyGraph1000000->SetLineColor(kRed);
MyGraph1000000->GetXaxis()->SetTitle("Time [s]");
MyGraph1000000->GetYaxis()->SetTitle("Number of Atoms");
MyGraph1000000->Draw("AP");
MyGraph1000000->SetMinimum(0.1);

TGraphErrors *MyGraph10000 = new TGraphErrors("decay10000.dat", "\%lg \%lg");
MyGraph10000->SetMarkerColor(kBlue);
MyGraph10000->SetLineColor(kBlue);
MyGraph10000->Draw("PSame");

TGraphErrors *MyGraph1000 = new TGraphErrors("decay1000.dat", "\%lg \%lg");
MyGraph1000->SetMarkerColor(kMagenta);
MyGraph1000->SetLineColor(kMagenta);
MyGraph1000->Draw("PSame");

TGraphErrors *MyGraph = new TGraphErrors("decay.dat", "\%lg \%lg");
MyGraph->SetMarkerColor(kGreen);
MyGraph->SetLineColor(kGreen);
 
MyGraph->Draw("PSame");

TLegend* leg = new TLegend(0.8,0.7,0.95,0.9);

leg->AddEntry(MyGraph1000000, "1000000 Entries", "PL");
leg->AddEntry(MyGraph10000, "10000 Entries", "PL");
leg->AddEntry(MyGraph1000, "1000 Entries", "PL");
leg->AddEntry(MyGraph, "500 Entries", "PL");
leg->SetFillColor(kWhite);
leg->Draw();


c1->SetLogy();
c1->Update();
}
