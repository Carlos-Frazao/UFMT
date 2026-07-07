"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
var __param = (this && this.__param) || function (paramIndex, decorator) {
    return function (target, key) { decorator(target, key, paramIndex); }
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.PersonagemService = void 0;
const common_1 = require("@nestjs/common");
const typeorm_1 = require("@nestjs/typeorm");
const typeorm_2 = require("typeorm");
const personagem_entity_1 = require("./entities/personagem.entity");
const personagens_seed_1 = require("./personagens.seed");
let PersonagemService = class PersonagemService {
    personagemRepository;
    constructor(personagemRepository) {
        this.personagemRepository = personagemRepository;
    }
    async onModuleInit() {
        const total = await this.personagemRepository.count();
        if (total === 0) {
            await this.personagemRepository.save(personagens_seed_1.personagensSeed);
        }
    }
    create(createPersonagemDto) {
        const personagem = this.personagemRepository.create(createPersonagemDto);
        return this.personagemRepository.save(personagem);
    }
    findAll() {
        return this.personagemRepository.find({ order: { ordem: 'ASC' } });
    }
    async findOne(id) {
        const personagem = await this.personagemRepository.findOneBy({ id });
        if (!personagem) {
            throw new common_1.NotFoundException('Personagem nao encontrado');
        }
        return personagem;
    }
    async update(id, updatePersonagemDto) {
        const personagem = await this.findOne(id);
        Object.assign(personagem, updatePersonagemDto);
        return this.personagemRepository.save(personagem);
    }
    async remove(id) {
        const personagem = await this.findOne(id);
        await this.personagemRepository.remove(personagem);
        return { mensagem: 'Personagem removido com sucesso' };
    }
};
exports.PersonagemService = PersonagemService;
exports.PersonagemService = PersonagemService = __decorate([
    (0, common_1.Injectable)(),
    __param(0, (0, typeorm_1.InjectRepository)(personagem_entity_1.Personagem)),
    __metadata("design:paramtypes", [typeorm_2.Repository])
], PersonagemService);
//# sourceMappingURL=personagem.service.js.map