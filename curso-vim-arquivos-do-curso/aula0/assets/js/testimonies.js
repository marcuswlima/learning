(function() {
	var id_ativo = 1;
	var dr_depoimentos = 3;

	var troca_depoimento = function(novo_id) {
		document.querySelector("#figura-"+id_ativo+"-depoimentos".classList.remove("active");
		document.querySelector("#botao-"+id_ativo+"-depoimentos".classList.remove("active");
		document.querySelector("#figura-"+novo_id+"-depoimentos".classList.add("active");
		document.querySelector("#botao-"+novo_id+"-depoimentos".classList.add("active");
		id_ativo = novo_id;
	};

	document.querySelector(".left").addEventoListener("click", function() {
		troca_depoimento(id_ativo - 1 + nr_depoimentos * (id_ativo == 1));
	});


	document.querySelector(".right").addEventoListener("click", function() {
		troca_depoimento(id_ativo + 1 - nr_depoimentos * (id_ativo == nr_depoimentos));
	});


})();
