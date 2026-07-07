import { CreatePersonagemDto } from './dto/create-personagem.dto';
import { UpdatePersonagemDto } from './dto/update-personagem.dto';
import { PersonagemService } from './personagem.service';
export declare class PersonagemController {
    private readonly personagemService;
    constructor(personagemService: PersonagemService);
    create(createPersonagemDto: CreatePersonagemDto): Promise<import("./entities/personagem.entity").Personagem>;
    findAll(): Promise<import("./entities/personagem.entity").Personagem[]>;
    findOne(id: string): Promise<import("./entities/personagem.entity").Personagem>;
    update(id: string, updatePersonagemDto: UpdatePersonagemDto): Promise<import("./entities/personagem.entity").Personagem>;
    remove(id: string): Promise<{
        mensagem: string;
    }>;
}
