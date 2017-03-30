
/**
* CompteOperations.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Compte.idl
* mardi 14 mars 2017 08 h 36 CET
*/

public interface CompteOperations 
{

  // Déposer un certain montant sur un compte
  void deposeLiquide (float Flottant);

  // Retirer dargent du compte (mais vous nautorisez pas le découvert !)
  boolean retireLiquide (float Flottant);

  // Afficher le montant deposé sur le compte
  float afficheMontant ();

  // et false est retournée
  boolean virementCompteaCompte (float Flottant, int Compte);
} // interface CompteOperations