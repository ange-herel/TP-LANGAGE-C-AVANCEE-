/*let variable3 = document.querySelector("#créercompteutilisateur");

if (variable3) { // Vérifie que l'élément existe
    variable3.addEventListener("click", () => {
        variable3.innerHTML = "<p>Compte créé avec succès !</p>";
    });
} else {
    console.error("L’élément #créercompteutilisateur n’a pas été trouvé !");
}*/
alert('presence site');
/*let formulaire=document.querySelector('.formulaire');
formulaire.addEventListener("submit", function(event){
       event.preventdefault();
       formulaire.style.display="none";
      let nom=document.getElementById('nom').value;
      document.getElementById('creer').textContent="votre compte a bel et bien été créer monsieur "+ " "+nom;
});*/
let formulaire = document.querySelector('.formulaire');

formulaire.addEventListener("submit", function (event) {
    event.preventDefault(); // Correction
    let nom = document.getElementById('nom').value; // Correction
    alert("Votre compte a été créer avec succés mr/mme "+ nom);
});
