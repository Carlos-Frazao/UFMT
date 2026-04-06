---
layout: default
---

<script>
    // Icone
  var favicon = document.createElement('link'); 
  favicon.rel = 'icon'; 
  favicon.href = './computador.png';
  document.head.appendChild(favicon);


  // Logo UFMT
  var titulos = document.querySelectorAll('h1, h2, a, .project-name');

  for (var i = 0; i < titulos.length; i++) {
    if (titulos[i].textContent.trim() === 'UFMT') {
      titulos[i].innerHTML = '<a href="/UFMT/"><img src="https://posgcd.ic.ufmt.br/wp-content/uploads/2023/02/cropped-Marca_UFMT_Vertical.png" alt="Logo UFMT" style="max-height: 80px; cursor: pointer; border: none;"></a>';
      break; // Substitui a logo e para a busca
    }
  }

  window.addEventListener('DOMContentLoaded', function() {
    var tituloCabecalho = document.querySelector('header h1') || document.querySelector('.project-name');
    if (tituloCabecalho) {
      tituloCabecalho.innerHTML = '<a href="/UFMT/"><img src="https://posgcd.ic.ufmt.br/wp-content/uploads/2023/02/cropped-Marca_UFMT_Vertical.png" alt="Logo UFMT" style="max-height: 80px; cursor: pointer;"></a>';
    }
  });
</script>

{% include_relative README.md %}