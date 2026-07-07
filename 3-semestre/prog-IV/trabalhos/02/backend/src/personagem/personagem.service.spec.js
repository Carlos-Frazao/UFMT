"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const common_1 = require("@nestjs/common");
const testing_1 = require("@nestjs/testing");
const typeorm_1 = require("@nestjs/typeorm");
const personagem_entity_1 = require("./entities/personagem.entity");
const personagem_service_1 = require("./personagem.service");
describe('PersonagemService', () => {
    let service;
    let repository;
    beforeEach(async () => {
        const module = await testing_1.Test.createTestingModule({
            providers: [
                personagem_service_1.PersonagemService,
                {
                    provide: (0, typeorm_1.getRepositoryToken)(personagem_entity_1.Personagem),
                    useValue: {
                        count: jest.fn(),
                        save: jest.fn(),
                        create: jest.fn(),
                        find: jest.fn(),
                        findOneBy: jest.fn(),
                        remove: jest.fn(),
                    },
                },
            ],
        }).compile();
        service = module.get(personagem_service_1.PersonagemService);
        repository = module.get((0, typeorm_1.getRepositoryToken)(personagem_entity_1.Personagem));
    });
    it('deve listar personagens ordenados pela ordem de apresentacao', async () => {
        const personagens = [
            {
                id: 1,
                titulo: 'Elliot Alderson',
                conteudo: 'Hacker',
                imagem: 'elliot.jpg',
                afiliacao: 'fsociety',
                ordem: 1,
            },
        ];
        repository.find.mockResolvedValue(personagens);
        await expect(service.findAll()).resolves.toEqual(personagens);
        expect(repository.find).toHaveBeenCalledWith({ order: { ordem: 'ASC' } });
    });
    it('deve criar um personagem', async () => {
        const dto = {
            titulo: 'Whiterose',
            conteudo: 'Lider do Dark Army',
            imagem: 'whiterose.jpg',
            afiliacao: 'dark-army',
            ordem: 2,
        };
        const personagem = { id: 1, ...dto };
        repository.create.mockReturnValue(personagem);
        repository.save.mockResolvedValue(personagem);
        await expect(service.create(dto)).resolves.toEqual(personagem);
        expect(repository.create).toHaveBeenCalledWith(dto);
    });
    it('deve lancar erro quando o personagem nao existir', async () => {
        repository.findOneBy.mockResolvedValue(null);
        await expect(service.findOne(99)).rejects.toBeInstanceOf(common_1.NotFoundException);
    });
});
//# sourceMappingURL=personagem.service.spec.js.map